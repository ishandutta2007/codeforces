#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
}

#ifdef LOCAL
//#define DEBUG
#endif

struct matrix{
	ll ar[2][2];
};

ostream& operator<<(ostream &cout, matrix m){
	cout << "[" << m.ar[0][0] << ", " << m.ar[0][1] << ", " << m.ar[1][0] << ", " << m.ar[1][1] << "]";
	return cout;
}

matrix operator*(matrix a, matrix b){
	matrix ans;
	//cout << a << "*" << b << "=";
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			ans.ar[i][j] = 0;
			for(int k = 0; k < 2; k++){
				ans.ar[i][j] += (a.ar[i][k] * b.ar[k][j]);
			}
			ans.ar[i][j] %= MOD;
		}
	}
	//cout << ans << endl;
	return ans;
}

matrix operator+(matrix a, matrix b){
	matrix ans;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			ans.ar[i][j] = (a.ar[i][j] + b.ar[i][j]) % MOD;
		}
	}
	return ans;
}



matrix _pow(matrix m, int n){
	if(n == 1)
		return m;
	if(n & 1)
		return (m * _pow(m, n - 1));
	m = _pow(m, n >> 1);
	m = m * m;
	return m;
}

matrix get_pow(ll k){
	matrix ans;
	ans.ar[0][0] = ans.ar[1][0] = ans.ar[1][1] = ans.ar[0][1] = 1;
	ans.ar[0][0] = 0;
	ans = _pow(ans, k);
	//cout << k << ": " << ans << endl;
	return ans;
}

matrix get_matrix(ll n){
	matrix ans;
	ans.ar[0][0] = ans.ar[0][1] = ans.ar[1][0] = ans.ar[1][1] = 0;
	ans.ar[0][1] = 1;
	if(n == 1)
		return ans;
	return ans * get_pow(n - 1);
}

matrix get_standart(){
	matrix ans;
	ans.ar[0][0] = ans.ar[1][1] = 1;
	ans.ar[0][1] = ans.ar[1][0] = 0;
	return ans;
}

matrix get_empty(){
	matrix ans;
	ans.ar[0][0] = ans.ar[0][1] = ans.ar[1][0] = ans.ar[1][1] = 0;
	return ans;
}

struct segment_tree{
	int n;
	matrix *m, *y;
	int *ar;
	void build(int v, int l, int r){
		y[v] = get_standart();
		if(l == r){
			m[v] = get_matrix(ar[l]);
			//cout << l << " " << m[v] << endl;
			return;
		}
		int x = (l + r) >> 1;
		build(v << 1, l, x);
		build(v << 1 | 1, x + 1, r);
		m[v] = m[v << 1] + m[v << 1 | 1];
		//cout << l << " " << r << " " << m[v] << endl;
	}
	segment_tree(int n, int *ar){
		this->n = n;
		this->ar = ar;
		y = new matrix[n << 2];
		m = new matrix[n << 2];
		build(1, 0, n - 1);
	}
	void push(int v){
		y[v << 1] = y[v << 1] * y[v];
		y[v << 1 | 1] = y[v << 1 | 1] * y[v];
		y[v] = get_standart();
	}
	void upd(int v, int tl, int tr, int l, int r, matrix &mm){
		if(l <= tl && tr <= r){
			//cout << "W " << y[v];
			y[v] = y[v] * mm;
			//cout << " " << y[v] << endl;
			//cout << "Upd " << tl << " " << tr << " " << m[v] << " ";
			m[v] = m[v] * mm;
			//cout << m[v] << endl;
			return;
		}
		if(tr < l || r < tl)
			return;
		//push(v);
		int x = (tl + tr) >> 1;
		upd(v << 1, tl, x, l, r, mm);
		upd(v << 1 | 1, x + 1, tr, l, r, mm);
		m[v] = (m[v << 1] + m[v << 1 | 1]) * y[v];
		//cout << tl << " " << tr << " " << m[v] << " " << y[v] << endl;
	}
	matrix get(int v, int tl, int tr, int l, int r){
		if(l <= tl && tr <= r){
			//cout << "@ " << tl << " " << tr << endl;
			return m[v];
		}
		if(tr < l || r < tl)
			return get_empty();
		//push(v);
		int x = (tl + tr) >> 1;
		return (get(v << 1, tl, x, l, r) + get(v << 1 | 1, x + 1, tr, l, r)) * y[v];
	}
	ll get(int l, int r){
		//cout << "# " << l << " " << r << endl;
		return get(1, 0, n - 1, l, r).ar[0][1];
	}
	void upd(int l, int r, int x){
		matrix m = get_pow(x);
		upd(1, 0, n - 1, l, r, m);
	}
};

struct solve_long{
	int *ar;
	solve_long(int *ar){
		this->ar = ar;
	}
	void upd(int l, int r, int x){
		for(int i = l; i <= r; i++)
			ar[i] += x;
	}
	ll get(int l, int r){
		ll ans = 0;
		for(int i = l; i <= r; i++){
			ans += get_matrix(ar[i]).ar[0][1];
		}
		return (ans % MOD);
	}
};

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif


	int n, m;
	cin >> n >> m;
	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	segment_tree tree(n, ar);
	get_pow(3);
	//solve_long sl(ar);
	while(m--){
		int t;
		cin >> t;
		if(t == 1){
			int l, r, x;
			cin >> l >> r >> x;
			//sl.upd(l - 1, r - 1, x);
			tree.upd(l - 1, r - 1, x);
		}else{
			int l, r;
			cin >> l >> r;
			//cout << sl.get(l - 1, r - 1) << endl;
			cout << tree.get(l - 1, r - 1) << endl;
		}
	}

}