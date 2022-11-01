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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, a[xn], b[xn], dp[xn], seg[xn << 2];
stack <int> st;

void build(int id, int l, int r){
	seg[id] = - INF;
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, mid, r), build(rc, mid, r);
}
void modify(int id, int l, int r, int pos, ll val){
	seg[id] = max(seg[id], val);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
}
ll get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return - INF;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return max(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}

int main(){
	InTheNameOfGod;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		cin >> b[i];
	st.push(0);
	build(1, 0, n);
	modify(1, 0, n, 0, 0);
	dp[0] = - INF;
	for (int i = 1; i <= n; ++ i){
		while (a[st.top()] > a[i])
			st.pop();
		int x = st.top();
		st.push(i);
		dp[i] = max(dp[x], get(1, 0, n, x, i) + b[i]);
		modify(1, 0, n, i, dp[i]);
	}
	cout << dp[n] << endl;

	return 0;
}