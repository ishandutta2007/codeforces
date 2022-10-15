#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-12;
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

const int MAX = 3e5 + 10;

vector<int> vec[MAX];
vector<int> v1[MAX], v2[MAX];
int leader[MAX];

int tin[MAX], tout[MAX];
int timer = 0;

int n, m;

int color[MAX];

int ans = 1;

void dfs(int pos){
	tin[pos] = ++timer;
	set<int> s;
	for(int a : v1[pos]){
		if(color[a]){
			assert(s.find(color[a]) == s.end());
			s.insert(color[a]);
		}
	}
	int now = 0;
	for(int a : v1[pos]){
		if(color[a])
			continue;
		now++;
		while(s.find(now) != s.end())
			now++;
		color[a] = now;
	}
	ans = max(ans, now);
	for(int a : vec[pos]){
		if(tin[a] == 0){
			dfs(a);
		}
	}
	tout[pos] = ++timer;
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

	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		while(a--){
			int b;
			cin >> b;
			v1[i].push_back(b);
			v2[b].push_back(i);
		}
	}

	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	int root = 1;

	dfs(root);

	cout << ans << endl;

	for(int i = 1; i <= m; i++){
		if(color[i] == 0){
			color[i] = 1;
		}
		cout << color[i] << " ";
	}

	cout << endl;

#ifdef LOCAL
	for(int i = 1; i <= n; i++){
		for(int l = 0; l < (int) v1[i].size(); l++){
			for(int r = l + 1; r < (int) v1[i].size(); r++){
				assert(color[v1[i][l]] != color[v1[i][r]]);
			}
		}
	}
#endif

}