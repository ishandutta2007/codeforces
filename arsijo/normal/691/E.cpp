#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
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
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

bool bol[100][100];
ll ar[100];
int n;

struct matrix{
	ll **ar, n;
	matrix(int n){
		this->n = n;
		ar = new ll*[n];
		for(int i = 0; i < n; i++){
			ar[i] = new ll[n];
			for(int j = 0; j < n; j++){
				ar[i][j] = 0;
			}
		}
	}
};

matrix operator*(matrix a, matrix b){
	int n = a.n;
	matrix ans(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int z = 0; z < n; z++){
				ans.ar[i][j] += (a.ar[i][z] * b.ar[z][j]) % MOD;
			}
			ans.ar[i][j] %= MOD;
		}
	}
	return ans;
}

matrix _pow(matrix a, ll n){
	if(n == 1)
		return a;
	if(n & 1)
		return a * _pow(a, n - 1);
	matrix ans = _pow(a, n >> 1);
	ans = ans * ans;
	return ans;
}

bool check(ll a, ll b){
	int res = 0;
	a ^= b;
	while(a){
		res += a & 1;
		a >>= 1;
	}
	return res % 3 == 0;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(5);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	ll k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	matrix res(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res.ar[i][j] = check(ar[i], ar[j]);
		}
	}
	matrix a(n);
	for(int i = 0; i < n; i++)
		a.ar[0][i] = 1;
	a = a * _pow(res, k - 1);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += a.ar[0][i];
	}
	cout << (ans % MOD) << endl;

}