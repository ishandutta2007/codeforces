// khodaya khodet komak kon
// Toxicity
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int qq, n, m, k, a[xn], ord[xn], ans[xn], b[xn];
set <pii> st;

bool cmp(int i, int j){
	return a[i] > a[j];
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], ord[i] = i;
		sort(ord + 1, ord + n + 1, cmp);
		st.clear();
		for (int i = 1; i <= m; ++ i)
			b[i] = 0, st.insert({0, i});
		for (int i = 1; i <= n; ++ i){
			int ind = ord[i];
			int x = st.begin() -> B;
			st.erase(st.begin());
			b[x] += a[ind], ans[ind] = x;
			st.insert({b[x], x});
		}
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++ i)
			cout << ans[i] << sep;
		cout << endl;
	}

	return 0;
}