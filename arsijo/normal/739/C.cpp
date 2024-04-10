#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
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
#define prev time_prev
#define remove tipa_remove
#define next tipa_next
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct thing{
	ll size, left, right, lsize, rsize, ans;
	thing(){
		size = left = right = lsize = rsize = ans = 0;
	}
	thing(ll val){
		size = 1;
		left = right = val;
		if(val){
			lsize = rsize = ans = 1;
		}else{
			lsize = rsize = ans = 0;
		}
	}
};

thing operator+(thing a, thing b){
	thing ans;
	if(a.size == 0)
		return b;
	if(b.size == 0)
		return a;
	//cout << "# " << endl;
	ans.size = a.size + b.size;
	ans.left = a.left;
	ans.right = b.right;
	ans.ans = max(a.ans, b.ans);
	ans.lsize = a.lsize;
	ans.rsize = b.rsize;
	if(ans.lsize == a.size && b.lsize && b.left != 0){
		if((a.right > 0) || (a.right < 0 && b.left < 0)){
			ans.lsize = a.size + b.lsize;
			ans.ans = max(ans.ans, ans.lsize);
		}
	}
	if(ans.rsize == b.size && a.rsize && a.right != 0){
		if((b.left < 0) || (b.left > 0 && a.right > 0)){
			ans.rsize = a.rsize + b.size;
			ans.ans = max(ans.ans, ans.rsize);
		}
	}
	if(a.rsize > 0 && b.lsize > 0 && a.right != 0 && b.left != 0){
		if((a.right > 0) || (a.right < 0 && b.left < 0)){
			ans.ans = max(ans.ans, a.rsize + b.lsize);
		}
	}
	//cout << "$" << endl;
	return ans;
}

struct segment_tree{
private:
	thing *t;
	ll *ar;
	int n;
	void build(int v, int l, int r, ll *ar){
		if(l == r){
			t[v] = thing(ar[l]);
			return;
		}
		int x = (l + r) >> 1;
		build(v << 1, l, x, ar);
		build(v << 1 | 1, x + 1, r, ar);
		t[v] = t[v << 1] + t[v << 1 | 1];
	}
	thing get(int v, int tl, int tr, int l, int r){
		if(l <= tl && tr <= r)
			return t[v];
		if(tr < l || r < tl)
			return thing();
		int x = (tl + tr) >> 1;
		return (get(v << 1, tl, x, l, r) + get(v << 1 | 1, x + 1, tr, l, r));
	}
	void upd(int v, int tl, int tr, int pos, ll val){
		//cout << tl << " " << tr << endl;
		if(tl == tr){
			ar[tl] += val;
			t[v] = thing(ar[tl]);
			return;
		}
		int x = (tl + tr) >> 1;
		if(pos <= x){
			upd(v << 1, tl, x, pos, val);
		}else{
			upd(v << 1 | 1, x + 1, tr, pos, val);
		}
		t[v] = t[v << 1] + t[v << 1 | 1];
		//cout << "% " << tl <<  " " << tr << endl;
	}
	void upd(int pos, ll val){
		//cout << "! " << pos << " "<< val << endl;
		upd(1, 2, n, pos, val);
	}
public:
	segment_tree(int n, ll *ar){
		this->n = n;
		t = new thing[(n + 2) << 2];
		this->ar = ar;
		if(n >= 2)
			build(1, 2, n, ar);
	}
	ll get(){
		if(n == 1)
			return 1;
		return t[1].ans + 1;
	}
	void upd(int l, int r, ll val){
		if(l >= 2){
			upd(l, val);
		}
		if(r < n){
			upd(r + 1, -val);
		}
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

	int n;
	cin >> n;

	ll ar[n + 2];
	for(int i = 1; i <= n; i++)
		cin >> ar[i];
	for(int i = n; i > 1; i--){
		ar[i] -= ar[i - 1];
	}

	segment_tree tree(n, ar);

	int m;
	cin >> m;

	while(m--){
		int l, r, d;
		cin >> l >> r >> d;
		tree.upd(l, r, d);
		cout << tree.get() << endl;
	}

	cout << endl;

}