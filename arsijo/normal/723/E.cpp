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
#define prev asdklhsdireufhdashj
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

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 201;
int ar[MAX][MAX];
int deg[MAX];
int n, m;
int t[MAX];
vector<ii> v;
void dfs(int pos){
	if(t[pos] == 0)
		t[pos] = 1;
	for(int &i = t[pos]; i <= n; i++){
		if(ar[pos][i]){
			v.push_back(make_pair(pos, i));
			deg[i]--, deg[pos]--;
			ar[pos][i] = ar[i][pos] = 0;
			dfs(i);
		}
	}
}
bool used[MAX];
bool _dfs(int pos){
	used[pos] = true;
	for(int i = 1; i <= n; i++){
		if(!used[i] && ar[pos][i]){
			if((deg[i] & 1) || _dfs(i)){
				ar[pos][i] = ar[i][pos] = 0;
				deg[pos]--, deg[i]--;
				v.push_back(make_pair(pos, i));
				return true;
			}
		}
	}
	return false;
}
void solve() {
	cin >> n >> m;
	ms(ar);
	ms(t);
	ms(deg);
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		deg[a]++, deg[b]++;
		ar[a][b] = ar[b][a] = true;
	}
	int ans = n;
	v.clear();
	for(int i = 1; i <= n; i++){
		if(deg[i] & 1){
			ms(used);
			assert(_dfs(i));
			ans -= 2;
		}
	}
	for(int i = 1; i <= n; i++){
		if(deg[i]){
			dfs(i);
		}
	}
	assert((int) v.size() == m);
	cout << ans << endl;
	for(ii a : v){
		cout << a.first << " " << a.second << endl;
	}
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int t;
	cin >> t;
	while(t--)
		solve();

}