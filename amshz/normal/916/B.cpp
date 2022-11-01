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

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, k, cnt[xn], res, ptr;
vector <ll> ans;
set <pll> st;

int main(){
	InTheNameOfGod;

	cin >> n >> k;
	for (ll bit = 0; bit < 63; ++ bit)
		if ((n & (1ll << bit)))
			++ cnt[bit + 500], ++ res;
	if (k < res)
		kill("No");
	cout << "Yes" << endl;
	for (int i = xn - 1; i >= 0; -- i){
		if (!cnt[i])
			continue;
		if (res + cnt[i] <= k)
			cnt[i - 1] += cnt[i] + cnt[i], res += cnt[i], cnt[i] = 0;
		else
			break;
	}
	for (int i = 0; i < xn; ++ i)
		while (cnt[i])
			st.insert({i, ++ ptr}), -- cnt[i];
	while (res < k){
		pll x = *st.begin();
		st.erase(st.begin());
		-- x.A;
		st.insert(x);
		x.B = ++ ptr;
		st.insert(x);
		++ res;
	}
	for (pll x : st)
		ans.push_back(x.A);
	reverse(all(ans));
	for (ll x : ans)
		cout << x - 500 << sep;
	cout << endl;

	return 0;
}