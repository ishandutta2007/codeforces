#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 1e5 + 10;
const int inf = 3e5;

int dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s, t = "CODEFORCES";
	cin >> s;
	int n = s.size();
	if (n < 10)
		return cout << "NO\n" << endl, 0;
	for (int i = 0; i <= 10; i++){
		int m = 10-i;
		string z = s.substr(0, i) + s.substr(n-m, m);
		if (t == z)
			return cout << "YES\n", 0;
	}
	cout << "NO\n";
}