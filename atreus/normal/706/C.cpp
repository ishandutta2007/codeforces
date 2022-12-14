#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

const int maxn = 1e5 + 500;
long long dp[maxn][3], c[maxn];
string s[maxn];

string revstr(string a){
	string rev;
	for (int i = a.size() - 1; i >= 0; i--)
		rev += a[i];
	return rev;
}

int main() {
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	dp[0][1] = 0;
	dp[0][2] = c[0];
	for (int i = 1; i < n; i++){
		string a = s[i], b = s[i - 1];
		if (a < b && a < revstr(b) && revstr(a) < b && revstr(a) < revstr(b))
			return cout << -1 << endl, 0;
		if (a >= b)
			dp[i][1] = dp[i - 1][1];
		else
			dp[i][1] = 1000000000000000000;
		if (a >= revstr(b))
			dp[i][1] = min(dp[i][1], dp[i - 1][2]);
		if (revstr(a) >= b)
			dp[i][2] = dp[i - 1][1] + c[i];
		else
			dp[i][2] = 1000000000000000000;
		if (revstr(a) >= revstr(b))
			dp[i][2] = min(dp[i][2], dp[i - 1][2] + c[i]); 
//		cout << dp[i][1] << " " << dp[i][2] << endl;
	}
	if (min(dp[n - 1][1], dp[n - 1][2]) == 1000000000000000000)
	    dp[n - 1][1] = -1;
	cout << min(dp[n - 1][1], dp[n - 1][2]) << endl;
}