#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
const int N = 100000;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c;
	string s;
	cin >> n >> c >> s;
	int num[c][c];
	fop (i,0,c) fop (j,0,c) num[i][j] = 0;
	fop (i,1,n) {
		num[s[i]-'a'][s[i-1]-'a']++;
		num[s[i-1]-'a'][s[i]-'a']++;
	}
	lli dp[1 << c];
	dp[0] = 0;
	fop (s,1,1 << c) {
		dp[s] = 1ll << 60;
		int k = __builtin_popcount(s);
		fop (i,0,c) {
			if (s & (1 << i)) {
				lli tmp = dp[s ^ (1 << i)];
				fop (j,0,c) {
					if (j == i) continue;
					if (s & (1 << j)) tmp += (1ll * num[i][j] * k);
					else tmp -= (1ll * num[i][j] * k);
				}
				dp[s] = min(dp[s], tmp);
			}
		}
	}
	cout << dp[(1 << c) - 1] << '\n';
}