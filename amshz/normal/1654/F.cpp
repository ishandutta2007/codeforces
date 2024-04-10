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
 
const int xn = 3e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int n, rnk[xm][xn], pw, P[xn];
string S;
 
bool cmp(int i, int j){
	if (rnk[pw - 1][i] != rnk[pw - 1][j])
		return rnk[pw - 1][i] < rnk[pw - 1][j];
	return rnk[pw - 1][i ^ (1 << (pw - 1))] < rnk[pw - 1][j ^ (1 << (pw - 1))];
}
void buildSA(){
	for (int i = 0; i < (1 << n); ++ i)
		rnk[0][i] = S[i] - 'a', P[i] = i;
	for (pw = 1; pw <= n; ++ pw){
		sort(P, P + (1 << n), cmp);
		for (int i = 1; i < (1 << n); ++ i)
			rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
	}
}
 
int main(){
	fast_io;
 
	cin >> n >> S;
	buildSA();
	for (int i = 0; i < (1 << n); ++ i)
		cout << S[i ^ P[0]];
	cout << endl;
 
	return 0;
}