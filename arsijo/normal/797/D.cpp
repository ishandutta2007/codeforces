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

int l[MAX], r[MAX], val[MAX], used[MAX];

set<int> s;

set<int> q;

int ans = 0;

void dfs(int v, int a, int b){
	if(val[v] < a || val[v] > b)
		s.insert(val[v]);
	else
		q.insert(val[v]);
	if(l[v] != -1)
		dfs(l[v], a, min(b, val[v] - 1));
	if(r[v] != -1)
		dfs(r[v], max(a, val[v] + 1), b);
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

	for(int i = 1; i <= n; i++){
		cin >> val[i] >> l[i] >> r[i];
		if(l[i] != -1)
			used[l[i]] = true;
		if(r[i] != -1)
			used[r[i]] = true;
	}

	int root = -1;

	for(int i = 1; i <= n; i++){
		if(!used[i]){
			root = i;
		}
	}

	assert(root != -1);

	dfs(root, -2e9, 2e9);

	int ans = 0;

	set<int> e;

	for(int a : s){
		if(q.find(a) == q.end()){
			e.insert(a);
		}
	}

	for(int i = 1; i <= n; i++){
		if(e.find(val[i]) != e.end()){
			ans++;
		}
	}

	cout << ans << endl;

}