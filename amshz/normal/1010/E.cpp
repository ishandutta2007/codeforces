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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int xmax[3], n, m, k, sz[xn << 2], b[xn][3];
int L[xn], R[xn], a[xn][3], mn[xn], mx[xn];
pii rmq[xm][xn];
vector <int> vec[xn << 2];
vector <ppi> Q[xn << 2];

bool cmp(int i, int j){
	return a[i][1] < a[j][1];
}
void modify(int id, int l, int r, int ind){
	vec[id].push_back(ind);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (a[ind][0] < mid)
		modify(id << 1, l, mid, ind);
	else
		modify(id << 1 | 1, mid, r, ind);
}
void build(int id, int l, int r){
	sort(all(vec[id]), cmp);
	sz[id] = SZ(vec[id]);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}
void add(int id, int l, int r, int ql, int qr, int yl, int yr, int dx){
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		int zl, zr, lb, rb, mid, ind;
		lb = - 1, rb = sz[id];
		while (rb - lb > 1){
			mid = lb + rb >> 1;
			ind = vec[id][mid];
			if (a[ind][1] < yl) lb = mid;
			else rb = mid;
		}
		zl = rb;
		lb = - 1, rb = sz[id];
		while (rb - lb > 1){
			mid = lb + rb >> 1;
			ind = vec[id][mid];
			if (a[ind][1] < yr) lb = mid;
			else rb = mid;
		}
		zr = rb;
		Q[id].push_back({{zl, zr}, dx});
		return;
	}
	int mid = l + r >> 1;
	add(id << 1, l, mid, ql, qr, yl, yr, dx);
	add(id << 1 | 1, mid, r, ql, qr, yl, yr, dx);
}
void get(int id, int l, int r){
	for (int i = 0; i < sz[id]; ++ i){
		int ind = vec[id][i];
		int x = xmax[2] + 1, y = 0;
		if (a[ind][2] < L[2])
			y = a[ind][2];
		else if (a[ind][2] > R[2])
			x = a[ind][2];
		else
			swap(x, y);
		rmq[0][i] = {x, y};
	}
	for (int i = 1; i < xm; ++ i){
		for (int j = 0; j < sz[id]; ++ j){
			rmq[i][j] = rmq[i - 1][j];
			if (j + (1 << (i - 1)) < sz[id]){
				rmq[i][j].A = min(rmq[i][j].A, rmq[i - 1][j + (1 << (i - 1))].A);
				rmq[i][j].B = max(rmq[i][j].B, rmq[i - 1][j + (1 << (i - 1))].B);
			}
		}
	}
	for (ppi x : Q[id]){
		int zl = x.A.A, zr = x.A.B, ind = x.B;
		for (int i = xm - 1; i >= 0; -- i){
			if (1 << i > zr - zl)
				continue;
			mn[ind] = min(mn[ind], rmq[i][zl].A);
			mx[ind] = max(mx[ind], rmq[i][zl].B);
			zl += 1 << i;
		}
	}
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	get(id << 1, l, mid);
	get(id << 1 | 1, mid, r);
}

int main(){
	InTheNameOfGod;
	
	for (int i = 0; i < 3; ++ i)
		cin >> xmax[i];
	cin >> n >> m >> k;
	for (int i = 0; i < 3; ++ i)
		L[i] = xmax[i] + 1;
	while (n --){
		int x[3];
		for (int j = 0; j < 3; ++ j){
			cin >> x[j];
			L[j] = min(L[j], x[j]);
			R[j] = max(R[j], x[j]);
		}
	}
	for (int i = 0; i < m; ++ i){
		int fl = 0;
		for (int j = 0; j < 3; ++ j){
			cin >> a[i][j];
			fl += (L[j] <= a[i][j] && a[i][j] <= R[j]);
		}
		if (fl == 3)
			kill("INCORRECT");
		modify(1, 1, xmax[0] + 1, i);
	}
	build(1, 1, xmax[0] + 1);
	cout << "CORRECT" << endl;
	for (int j = 0; j < k; ++ j){
		for (int i = 0; i < 3; ++ i)
			cin >> b[j][i];
		mx[j] = 0, mn[j] = xmax[2] + 1;
		int xl = min(L[0], b[j][0]), xr = max(R[0], b[j][0]);
		int yl = min(L[1], b[j][1]), yr = max(R[1], b[j][1]);
		add(1, 1, xmax[0] + 1, xl, xr + 1, yl, yr + 1, j);
	}
	get(1, 1, xmax[0] + 1);
	for (int j = 0; j < k; ++ j){
		bool fl1 = false, fl2 = true;
		for (int i = 0; i < 3; ++ i)
			fl1 |= (b[j][i] < L[i]) | (b[j][i] > R[i]);
		if (mn[j] <= b[j][2] || b[j][2] <= mx[j]) fl2 = false;
		if (fl1 && fl2) cout << "UNKNOWN" << endl;
		else if (fl1) cout << "CLOSED" << endl;
		else cout << "OPEN" << endl;
	}
	
	return 0;
}