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
const int mod[2] = {998244353, 1000000007};
const int base = 257;

int n, m, a[xn], b[xn], seg[xn << 2][2], res[2], P[xn], sum[2];
int lazy[xn << 2], pw[2][xn], inv[2][xn], ans, fen[xn];
bool flag;

void mofen(int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[pos] += val;
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; pos > 0; pos -= pos & - pos)
		res += fen[pos];
	return res;
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	for (int i = 0; i < 2; ++ i){
		if (lazy[id] > 0)
			seg[id][i] = 1ll * seg[id][i] * pw[i][lazy[id]] % mod[i];
		else
			seg[id][i] = 1ll * seg[id][i] * inv[i][- lazy[id]] % mod[i];
	}
	if (r - l > 1){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void modify(int id, int l, int r, int pos, int val){
	shift(id, l, r);
	if (r - l == 1){
		if (val != - 1)
			for (int i = 0; i < 2; ++ i)
				seg[id][i] = 1ll * pw[i][val] * b[pos] % mod[i];
		else
			seg[id][0] = seg[id][1] = 0;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val), shift(rc, mid, r);
	else
		modify(rc, mid, r, pos, val), shift(lc, l, mid);
	for (int i = 0; i < 2; ++ i)
		seg[id][i] = (seg[lc][i] + seg[rc][i]) % mod[i];
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	for (int i = 0; i < 2; ++ i)
		seg[id][i] = (seg[lc][i] + seg[rc][i]) % mod[i];
}
void add(int id){
	modify(1, 0, m, id, gefen(id - 1));
	update(1, 0, m, id + 1, m, 1);
	mofen(id, 1);
}
void remove(int id){
	modify(1, 0, m, id, - 1);
	update(1, 0, m, id + 1, m, - 1);
	mofen(id, - 1);
}

int main(){
	InTheNameOfGod;
	
	for (int i = 0; i < 2; ++ i){
		pw[i][0] = inv[i][0] = 1;
		pw[i][1] = base, inv[i][1] = power(base, mod[i] - 2, mod[i]);
		for (int j = 2; j < xn; ++ j){
			pw[i][j] = 1ll * pw[i][j - 1] * pw[i][1] % mod[i];
			inv[i][j] = 1ll * inv[i][j - 1] * inv[i][1] % mod[i];
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; ++ i){
		cin >> a[i];
		for (int j = 0; j < 2; ++ j){
			res[j] = (res[j] + 1ll * a[i] * pw[j][i] % mod[j]) % mod[j];
			sum[j] = (sum[j] + pw[j][i]) % mod[j];
		}
	}
	for (int i = 0; i < m; ++ i)
		cin >> b[i], P[b[i]] = i;
	for (int i = 1; i <= n; ++ i)
		add(P[i]);
	flag = true;
	for (int i = 0; i < 2; ++ i)
		flag &= res[i] == seg[1][i];
	ans += flag;
	for (int i = n + 1; i <= m; ++ i){
		remove(P[i - n]), add(P[i]), flag = true;
		for (int j = 0; j < 2; ++ j)
			flag &= seg[1][j] == (res[j] + 1ll * (i - n) * sum[j] % mod[j]) % mod[j];
		ans += flag;
	}
	cout << ans << endl;

	return 0;
}