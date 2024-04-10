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
 
const int xn = 2e5 + 10;
const int xm = 10 + 1;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, k, seg[xn << 2][xm][xm], lazy[xn << 2], P[xm];
pii a[xn << 2];
string s;

void build(int id, int l, int r){
	lazy[id] = - 1;
	if (r - l == 1){
		a[id] = {s[l] - 'a', s[l] - 'a'};
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	for (int i = 0; i < k; ++ i)
		for (int j = 0; j < k; ++ j)
			seg[id][i][j] = seg[id << 1][i][j] + seg[id << 1 | 1][i][j];
	a[id].A = a[id << 1].A;
	a[id].B = a[id << 1 | 1].B;
	++ seg[id][a[id << 1].B][a[id << 1 | 1].A];
}
void shift(int id, int l, int r){
	if (lazy[id] == - 1)
		return;
	for (int i = 0; i < k; ++ i)
		for (int j = 0; j < k; ++ j)
			seg[id][i][j] = 0;
	seg[id][lazy[id]][lazy[id]] = r - l - 1;
	a[id] = {lazy[id], lazy[id]};
	if (r - l > 1){
		lazy[id << 1] = lazy[id];
		lazy[id << 1 | 1] = lazy[id];
	}
	lazy[id] = - 1;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	for (int i = 0; i < k; ++ i)
		for (int j = 0; j < k; ++ j)
			seg[id][i][j] = seg[id << 1][i][j] + seg[id << 1 | 1][i][j];
	a[id].A = a[id << 1].A;
	a[id].B = a[id << 1 | 1].B;
	++ seg[id][a[id << 1].B][a[id << 1 | 1].A];
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> k >> s;
	build(1, 0, n);
	while (m --){
		int t, l, r;
		string p;
		cin >> t;
		if (t == 1){
			char c;
			cin >> l >> r >> c;
			update(1, 0, n, l - 1, r, c - 'a');
		}
		else{
			cin >> p;
			for (int i = 0; i < k; ++ i)
				P[p[i] - 'a'] = i;
			int ans = 1;
			for (int i = 0; i < k; ++ i)
				for (int j = 0; j < k; ++ j)
					if (P[i] >= P[j])
						ans += seg[1][i][j];
			cout << ans << endl;
		}
	}
	
	return 0;
}