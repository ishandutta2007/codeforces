# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;
const int base = 257;

ll n, q, a[xn], b[xn], ans[xn], nxt[xn], num[xn], seg[xn << 2];
pair <ll, ll> lazy[xn << 2];
vector <pii> Q[xn];
stack <int> st;

void update(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql) return;
	if (ql <= l && r <= qr){
		lazy[id].A += l - ql + 1;
		++ lazy[id].B;
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr);
	update(id << 1 | 1, mid, r, ql, qr);
}
void modify(int id, int l, int r, int ql, int qr, int val){
	if (qr <= l || r <= ql) return;
	if (ql <= l && r <= qr){
		seg[id] += val;
		return;
	}
	int mid = l + r >> 1;
	modify(id << 1, l, mid, ql, qr, val);
	modify(id << 1 | 1, mid, r, ql, qr, val);
}
ll get(int id, int l, int r, int pos){
	ll res = seg[id] + lazy[id].A + (pos - l) * lazy[id].B;
	if (r - l == 1) return res;
	int mid = l + r >> 1;
	if (pos < mid) res += get(id << 1, l, mid, pos);
	else res += get(id << 1 | 1, mid, r, pos);
	return res;
}

void solve(){
	for (int i = 1; i <= n; ++ i) Q[i].clear();
	while (st.size()) st.pop();
	for (int i = n; i >= 1; -- i){
		while (st.size() && num[st.top()] < num[i]) st.pop();
		if (st.size()) nxt[i] = st.top();
		else nxt[i] = n + 1;
		st.push(i);
	}
	memset(lazy, 0, sizeof lazy);
	memset(seg, 0, sizeof seg);
	for (int i = 1; i <= q; ++ i) Q[a[i]].push_back({b[i], i});
	for (int i = n; i >= 1; -- i){
		update(1, 1, n + 1, i, nxt[i]);
		modify(1, 1, n + 1, nxt[i], n + 1, nxt[i] - i);
		for (pii x : Q[i]) ans[x.B] += get(1, 1, n + 1, x.A);
	}
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> num[i];
    for (int i = 1; i <= q; ++ i) cin >> a[i];
    for (int i = 1; i <= q; ++ i) cin >> b[i];
    solve();
    reverse(num + 1, num + n + 1);
    for (int i = 1; i <= q; ++ i){
    	a[i] = n - a[i] + 1;
    	b[i] = n - b[i] + 1;
    	swap(a[i], b[i]);
	}
	solve();
	for (int i = 1; i <= q; ++ i) cout << ans[i] - (b[i] - a[i] + 1) << sep;
	cout << endl;
	
    return 0;
}