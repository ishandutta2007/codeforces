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
#ifndef LLONG_MAX
#define LLONG_MAX LONG_LONG_MAX
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

inline void upd(ll &a, ll b){
	a = min(a, b);
}

int main() {
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}

	ll ar[n][n];
	ll sum = 0;
	int ind = -1;
	for(int i = 0; i < n; i++){
		bool ok = true;
		for(int j = 0; j < n; j++){
			cin >> ar[i][j];
			if(!ar[i][j]){
				ok = false;
			}
		}
		if(ok){
			sum = 0;
			for(int j = 0; j < n; j++)
				sum += ar[i][j];
		}else{
			ind = i;
		}
	}

	for(int i = 0; i < n; i++)
		sum -= ar[ind][i];

	if(sum <= 0){
		cout << -1 << endl;
		return 0;
	}
	ll ans = sum;
	for(int i = 0; i < n; i++){
		if(!ar[ind][i])
			ar[ind][i] = sum;
	}

	set<ll> s;
	for(int i = 0; i < n; i++){
		ll sum = 0;
		for(int j = 0; j < n; j++)
			sum += ar[i][j];
		s.insert(sum);
		sum = 0;
		for(int j = 0; j < n; j++)
			sum += ar[j][i];
		s.insert(sum);
	}
	sum = 0;
	for(int i = 0; i < n; i++)
		sum += ar[i][i];
	s.insert(sum);
	sum = 0;
	for(int i = 0; i < n; i++)
		sum += ar[i][n - 1 - i];
	s.insert(sum);
	if((int) s.size() > 1){
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;

}