//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = 17;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, last[26], L[xn], R[xn], psL[xn][27], psR[xn][27], dp[xn][27], pd[xn][27];
int ptL[xn], ptR[xn], DP[xm][xn], PD[xm][xn];
string S;
ll dps[xm][xn], pds[xm][xn], ans;

int main() {
	fast_io;

	cin >> S;
	n = SZ(S);
	for (int i = 0; i < n; ++ i){
		L[i] = last[S[i] - 'a'];
		last[S[i] - 'a'] = i;
		for (int j = 0; j < 26; ++ j)
			psL[i][j] = last[j];
		sort(psL[i], psL[i] + 26);
		reverse(psL[i], psL[i] + 26);
		psL[i][26] = - 1;
	}
	fill(last, last + 26, n - 1);
	for (int i = n - 1; 0 <= i; -- i){
		R[i] = last[S[i] - 'a'];
		last[S[i] - 'a'] = i;
		for (int j = 0; j < 26; ++ j)
			psR[i][j] = last[j];
		sort(psR[i], psR[i] + 26);
		psR[i][26] = n;
	}
	for (int i = 0; i < n; ++ i){
		ptL[i] = ptR[i] = dp[i][0] = pd[i][0] = i;
		for (int j = 0; j < 26; ++ j){
			dp[i][j + 1] = min(dp[i][j], L[psR[i][j]]);
			pd[i][j + 1] = max(pd[i][j], R[psL[i][j]]);
		}
	}
	for (int _ = 1; _ <= 26; ++ _){
		for (int i = 0; i < n; ++ i){
			DP[0][i] = dp[i][_];
			PD[0][i] = pd[i][_];
			dps[0][i] = pds[0][i] = i;
		}
		for (int i = 1; (1 << i) <= n; ++ i){
			for (int j = 0; j < n; ++ j){
				DP[i][j] = DP[i - 1][DP[i - 1][j]];
				PD[i][j] = PD[i - 1][PD[i - 1][j]];
				dps[i][j] = dps[i - 1][j] + dps[i - 1][DP[i - 1][j]];
				pds[i][j] = pds[i - 1][j] + pds[i - 1][PD[i - 1][j]];
			}
		}
		for (int i = 0; i < n; ++ i){
			for (int j = 31 - __builtin_clz(n); 0 <= j; -- j){
				int nxL = DP[j][ptL[i]], nxR = PD[j][ptR[i]];
				if (nxR < psR[nxL][_]){
					ans += (ll(n - 1) << j) + dps[j][ptL[i]] - pds[j][ptR[i]];
					ptL[i] = nxL, ptR[i] = nxR;
				}
			}
			if (ptR[i] < psR[ptL[i]][_]){
				ans += n - 1 + ptL[i] - ptR[i];
				ptL[i] = dp[ptL[i]][_];
				ptR[i] = pd[ptR[i]][_];
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}