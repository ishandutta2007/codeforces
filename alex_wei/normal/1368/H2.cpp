#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define i128 __int128
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>
#define pll pair <ll, ll>
#define pii pair <int, int>

#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return x = sgn ? -x : x;
	}
	template <typename T>
	inline void recprint(T x) {if(x >= 10) recprint(x / 10); pc(x % 10 + '0');}
	template <typename T>
	inline void print(T x) {if(x < 0) pc('-'), x = -x; recprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 1e5 + 5;

struct Mat {
	int a[2][2];
	friend Mat operator * (Mat x, Mat y) {
		Mat z; mem(z.a, 0x3f, 2);
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					cmin(z.a[i][j], x.a[i][k] + y.a[k][j]);
		return z;
	}
};

struct Seg {
	Mat a[4][N << 2], val[4][N << 2];
	int tag[N << 2], c[N], d[N], numl[N << 2], numr[N << 2];
	void push(int x) {
		for(int i = 0; i < 4; i++) val[i][x] = val[i][x << 1] * val[i][x << 1 | 1];
		numl[x] = numl[x << 1] + numl[x << 1 | 1];
		numr[x] = numr[x << 1] + numr[x << 1 | 1];
	}
	void build(int l, int r, int x) {
		if(l == r) {
			for(int i = 0; i < 4; i++) val[i][x] = a[i][l];
			numl[x] = c[l], numr[x] = d[l];
			return;
		}
		int m = l + r >> 1;
		build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
		push(x);
	}
	void flip(int l, int r, int x, int v) {
		for(int i = 0; i < 4; i++) if(i < (i ^ v))
			swap(val[i][x], val[i ^ v][x]);
		if(v == 1 || v == 3) numl[x] = r - l + 1 - numl[x];
//		cerr << "flip " << l << " " << r << " " << x << " " << v << " " << numl[x] << endl;
		if(v == 2 || v == 3) numr[x] = r - l + 1 - numr[x];
		tag[x] ^= v;
	}
	void push(int l, int r, int x) {
		if(tag[x]) {
//			cerr << "pushdown " << l << " " << r << " " << x << " " << tag[x] << "\n";
			int m = l + r >> 1;
			flip(l, m, x << 1, tag[x]);
			flip(m + 1, r, x << 1 | 1, tag[x]);
			tag[x] = 0;
		}
	}
	void modify(int l, int r, int ql, int qr, int x, int v) {
		if(ql <= l && r <= qr) return flip(l, r, x, v);
		int m = l + r >> 1; push(l, r, x);
		if(ql <= m) modify(l, m, ql, qr, x << 1, v);
		if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
		push(x);
//		cerr << "modify " << l << " " << r << " " << x << " " << numl[x] << endl;
	}
	int query(int l, int r, int ql, int qr, int x, int type) {
		if(ql <= l && r <= qr) return type ? numr[x] : numl[x];
		int m = l + r >> 1, ans = 0;
		if(ql <= m) ans = query(l, m, ql, qr, x << 1, type);
		if(m < qr) ans += query(m + 1, r, ql, qr, x << 1 | 1, type);
		return ans;
	}
} row, col;
int n, m, q, lr, rr, tr, br; // 0 -> R, 1 -> B
char l[N], r[N], t[N], b[N];
int calc() {
	assert(0 <= tr && tr <= m && 0 <= lr && lr <= n);
	Mat ro; ro.a[0][0] = m - tr, ro.a[0][1] = tr, ro = ro * row.val[0][1];
	Mat co; co.a[0][0] = n - lr, co.a[0][1] = lr, co = co * col.val[0][1];
	return min(min(ro.a[0][0] + m - br, ro.a[0][1] + br), 
				min(co.a[0][0] + n - rr, co.a[0][1] + rr));
}
void fr(int p) {
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++) {
			int cst = (i != j) * m; char ch = j ? 'B' : 'R';
			row.a[0][p].a[i][j] = cst + (ch != l[p]) + (ch != r[p]);
			row.a[1][p].a[i][j] = cst + (ch == l[p]) + (ch != r[p]);
			row.a[2][p].a[i][j] = cst + (ch != l[p]) + (ch == r[p]);
			row.a[3][p].a[i][j] = cst + (ch == l[p]) + (ch == r[p]);
		}
}
void fc(int p) {
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++) {
			int cst = (i != j) * n; char ch = j ? 'B' : 'R';
			col.a[0][p].a[i][j] = cst + (ch != t[p]) + (ch != b[p]);
			col.a[1][p].a[i][j] = cst + (ch == t[p]) + (ch != b[p]);
			col.a[2][p].a[i][j] = cst + (ch != t[p]) + (ch == b[p]);
			col.a[3][p].a[i][j] = cst + (ch == t[p]) + (ch == b[p]);
		}
}

bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> m >> q >> l + 1 >> r + 1 >> t + 1 >> b + 1;
	for(int i = 1; i <= n; i++) lr += row.c[i] = l[i] == 'R', rr += row.d[i] = r[i] == 'R';
	for(int i = 1; i <= m; i++) tr += col.c[i] = t[i] == 'R', br += col.d[i] = b[i] == 'R';
	for(int i = 1; i <= n; i++) fr(i);
	for(int i = 1; i <= m; i++) fc(i);
	row.build(1, n, 1), col.build(1, m, 1), cout << calc() << "\n";
	for(int i = 1; i <= q; i++) {
		char op; int l, r; scanf("%s %d %d", &op, &l, &r);
		if(op == 'L') {
			row.modify(1, n, l, r, 1, 1);
			lr = row.query(1, n, 1, n, 1, 0);
		}
		if(op == 'R') {
			row.modify(1, n, l, r, 1, 2);
			rr = row.query(1, n, 1, n, 1, 1);
		}
		if(op == 'U') {
			col.modify(1, m, l, r, 1, 1);
			tr = col.query(1, m, 1, m, 1, 0);
		}
		if(op == 'D') {
			col.modify(1, m, l, r, 1, 2);
			br = col.query(1, m, 1, m, 1, 1);
		}
		print(calc()), pc('\n'); 
	}
	return cerr << "Time : " << clock() << endl, flush(), 0;
} ///////////