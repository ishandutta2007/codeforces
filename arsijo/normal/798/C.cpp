#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-5;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef M_PI
#define M_PI 3.141592653589793238462643383
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

int gcd(int a, int b){
	while(a && b)
		a >= b ? a %= b : b %= a;
	return a + b;
}

int solve_long(vector<int> v){
	int n = (int) v.size();
	queue<pair<vector<int>, int> > q;
	q.push(make_pair(v, 0));
	for(int i = 0; i < 1e5; i++){
		vector<int> w = q.front().first;
		int ans = q.front().second;
		int g = abs(w[0]);
		q.pop();
		for(int i = 1; i < n; i++){
			g = gcd(g, abs(w[i]));
		}
		if(g > 1){
			for(int a : w){
				cout << a << " ";
			}
			cout << endl;
			return ans;
		}
		for(int i = 0; i + 1 < n; i++){
			vector<int> g;
			g.insert(g.end(), w.begin(), w.end());
			g[i] = w[i] - w[i + 1];
			g[i + 1] = w[i] + w[i + 1];
			q.push(make_pair(g, ans + 1));
		}
	}
	return -1;
}

int solve_ok(vector<ll> v){
	int w = v[0];
	for(int i = 1; i < (int) v.size(); i++){
		w = gcd(w, v[i]);
	}
	if(w > 1)
		return 0;
	int ans = 0;
	for(int i = 0; i + 1 < (int) v.size(); i++){
		while(abs(v[i]) % 2 == 1 || (i + 2 == (int) v.size() && (abs(v[i + 1]) % 2 == 1))){
			ll a = v[i] - v[i + 1];
			ll b = v[i] + v[i + 1];
			v[i] = a;
			v[i + 1] = b;
			ans++;
		}
	}
	return ans;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<ll> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	cout << "YES" << endl;
	cout << solve_ok(v) << endl;

}