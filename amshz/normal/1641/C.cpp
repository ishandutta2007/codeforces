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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, q, fen[xn], seg[xn << 2];
pii last[xn << 2];
bool lazy[xn << 2];

void mofen(int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[pos] += val;
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res += fen[pos];
	return res;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = n + 1;
		last[id] = {l, l};
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = min(seg[lc], seg[rc]);
	last[id].A = min(last[lc].A, last[rc].A);
	last[id].B = max(last[lc].B, last[rc].B);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	last[id] = {n + 1, 0};
	if (1 < r - l)
		lazy[lc] = lazy[rc] = 1;
	lazy[id] = false;
}
void update(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = true;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr);
	update(rc, mid, r, ql, qr);
	//seg[id] = min(seg[lc], seg[rc]);
	last[id].A = min(last[lc].A, last[rc].A);
	last[id].B = max(last[lc].B, last[rc].B);
}
void modify(int id, int l, int r, int pos, int val){
	seg[id] = min(seg[id], val);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
	seg[id] = min(seg[lc], seg[rc]);
	//last[id].A = min(last[lc].A, last[rc].A);
	//last[id].B = max(last[lc].B, last[rc].B);
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return n + 1;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return min(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}
int getR(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return n + 1;
	if (ql <= l && r <= qr)
		return last[id].A;
	int mid = l + r >> 1;
	return min(getR(lc, l, mid, ql, qr), getR(rc, mid, r, ql, qr));
}
int getL(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return last[id].B;
	int mid = l + r >> 1;
	return max(getL(lc, l, mid, ql, qr), getL(rc, mid, r, ql, qr));
}

int main(){
	fast_io;

	cin >> n >> q;
	build(1, 1, n + 1);
	while (q --){
		int t, l, r, x;
		cin >> t;
		if (t){
			cin >> x;
			if (gefen(x))
				cout << "NO" << endl;
			else{
				int l = getL(1, 1, n + 1, 1, x);
				int r = getR(1, 1, n + 1, x + 1, n + 1);
				if (get(1, 1, n + 1, l + 1, r) < r)
					cout << "YES" << endl;
				else
					cout << "N/A" << endl;
			}
		}
		else{
			cin >> l >> r >> x;
			if (x)
				modify(1, 1, n + 1, l, r);
			else{
				mofen(l, 1), mofen(r + 1, - 1);
				update(1, 1, n + 1, l, r + 1);
			}
		}
	}

	return 0;
}