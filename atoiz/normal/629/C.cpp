#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int BASE = 1e9 + 7;
const int MAX_DIF = 2017;

int calcMinPlus(string& s)
{
	int p = 0, cur = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') ++cur;
		else --cur;
		p = min(cur, p);
	}
	return p;
}

int calcPlus(string& s)
{
	int cur = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') ++cur;
		else --cur;
	}
	return cur;
}

vector< vector<int> > calcDP()
{
	vector< vector<int> > dp = vector< vector<int> >(MAX_DIF, vector<int>(MAX_DIF, 0));
	dp[0][0] = 1;

	for (int i = 1; i < MAX_DIF; ++i) {
		for (int j = 0; j < MAX_DIF; ++j) {
			if (j > 0) 			 dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % BASE;
			if (j < MAX_DIF - 1) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % BASE;
		}
	}

	return dp;
}

int mul(int a, int b)
{
	long long res = a;
	res *= b;
	res %= BASE;
	return res;
}

void test(vector< vector<int> >& dp)
{
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n, m, dif;
	cin >> n >> m;
	dif = n - m;
	string s;
	cin >> s;

	int minP = calcMinPlus(s), p = calcPlus(s);
	vector< vector<int> > dp = calcDP();
	// test(dp);

	int cnt = 0;
	for (int i = 0; i <= dif; ++i) {
		for (int j = -minP; j < MAX_DIF; ++j) {
			if (j + p < MAX_DIF)
				cnt = (cnt + mul(dp[i][j], dp[dif-i][j+p])) % BASE;
		}
	}

	cout << cnt << endl;
}