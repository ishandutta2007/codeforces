#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<bitset>
using namespace std;
//#define double long long;
int gcd(int i, int j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
typedef long double ld;
#define double long double
const double e = 0.000000000001;
const double pi = 3.1415926535898;
inline int getint() {
	int val = 0;
	char c;
	while ((c = getchar()) && !(c >= '0' && c <= '9'));
	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));
	return val;
}
const long long INF = 100000000000000;
const int Y = 200100;
long long c[Y];
long long P[Y];
int n, k;
bool f(long long t) {
	for (int i = k; i > 0; --i) {
		if (c[i] * t < P[i])return false;
	}
	return true;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	// freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	cout.precision(15);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		P[tmp]++;
	}
	for (int i = 1; i <= k; ++i)cin >> c[i];
	for (int i = k; i > 0; --i)P[i] += P[i + 1];
	int b = 0, e = n;
	while (b + 1 != e) {
		int mid = (b + e) / 2;
		if (f(mid))e = mid;
		else b = mid;
	}
	vector<vector<int>>ans = vector<vector<int>>(e);
	int yk = 0;
	for (int i = 1; i <= k; ++i) {
		P[i] -= P[i + 1];
		for (int j = 0; j < P[i]; ++j) {
			ans[yk++].push_back(i);
			if (yk == e)yk = 0;
		}
	}

	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x.size() << " ";
		for (auto x1 : x)cout << x1 << " ";
		cout << "\n";
	}
	return 0;
}