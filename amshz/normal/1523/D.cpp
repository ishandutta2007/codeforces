//khodaya khodet komak kon
# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, p, b[xn];
ll a[xn], ted, ans;
string S;
vector <int> vec;

void solve(ll mask){
	vec.clear();
	for (int i = 0; i < m; ++ i)
		if ((mask & (1ll << i)))
			vec.push_back(i);
	ll t = SZ(vec);
	for (int i = 0; i < (1 << t); ++ i)
		b[i] = 0;
	for (int i = 1; i <= n; ++ i){
		ll mask2 = 0;
		for (int j = 0; j < t; ++ j)
			if ((a[i] & (1ll << vec[j])))
				mask2 += (1ll << j);
		++ b[mask2];
	}
	for (int i = 1; i < (1 << t); ++ i)
		for (int j = i; j > 0; j = (j - 1) & i)
			if (i != j)
				b[j] += b[i];
	for (int i = 1; i < (1 << t); ++ i){
		ll mask2 = 0;
		for (int j = 0; j < t; ++ j)
			if ((i & (1 << j)))
				mask2 += (1ll << vec[j]);
		if (b[i] + b[i] >= n && __builtin_popcount(i) > ted)
			ted = __builtin_popcount(i), ans = mask2;
	}
}

int main(){
	InTheNameOfGod;
	srand(time(0));

	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++ i){
		cin >> S;
		for (int j = 0; j < m; ++ j)
			if (S[j] - '0')
				a[i] += (1ll << j);
	}
	random_shuffle(a + 1, a + n + 1);
	for (int i = 1; i <= min(n, 15); ++ i)
		solve(a[i]);
	for (int i = 0; i < m; ++ i){
		if ((ans & (1ll << i)))
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;

	return 0;
}