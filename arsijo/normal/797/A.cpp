#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
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

const int MAX = 1e5 + 10;

vector<ll> vec[MAX];

void dfs(int used, vector<ll> v) {
	ll sum = 0;
	for (ll a : v) {
		sum += sqr(a);
	}
	vec[used].push_back(sum);
	for (int i = 0; i < (int) v.size(); i++) {
		for (int j = i + 1; j < (int) v.size(); j++) {
			vector<ll> t;
			for (int a = 0; a < (int) v.size(); a++) {
				if (a != i && a != j) {
					t.push_back(v[a]);
				}
			}
			t.push_back(v[i] + v[j]);
			dfs(used + 1, t);
		}
	}
}

inline ld get(vector<ll> v) {
	ld sum = 0;
	for (ll a : v) {
		sum += (ld) a / (ld) v.size();
	}
	return sum;
}

int sum(int n){
	return (n * (n + 1)) / 2;
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

	vector<int> v;
	for(int i = 2; i <= n; i++){
		while(n % i == 0){
			v.push_back(i);
			n /= i;
		}
	}

	int k;
	cin >> k;

	if(k > (int) v.size()){
		cout << -1 << endl;
		return 0;
	}

	while((int) v.size() > k){
		int a = v.back();
		v.pop_back();
		v.back() *= a;
	}

	for(int a : v){
		cout << a << " ";
	}
}