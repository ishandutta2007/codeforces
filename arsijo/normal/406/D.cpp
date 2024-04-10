#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-8;
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
char wwww[12];
int kkkk;
inline void write(int x) {
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
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1e5 + 1;
int n;
#define x first
#define y second
ii ar[MAX];
int to[MAX];

ll get(ii a, ii b, ii c){
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

bool check(ii a, ii b, ii c){
	return get(a, b, c) > 0;
}

vector<int> vec[MAX];

int prev[MAX], tin[MAX], tout[MAX], timer = 0;
const int MAX_LOG = 20;
int up[MAX_LOG][MAX];
void dfs(int pos){
	tin[pos] = ++timer;
	dbg cout << "tin " << pos << endl;
	for(int i = 0; i < (int) vec[pos].size(); i++)
		dfs(vec[pos][i]);
	dbg cout << "tout " << pos << endl;
	tout[pos] = ++timer;
}

bool upper(int a, int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b){
	if(upper(a, b))
		return a;
	if(upper(b, a))
		return b;
	dbg cout << "@ " << a << " " << b << endl;
	for(int i = MAX_LOG - 1; i >= 0; i--){
		if(up[i][a] && !upper(up[i][a], b)){
			a = up[i][a];
		}
	}
	dbg cout << a << endl;
	return up[0][a];
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> ar[i].x >> ar[i].y;
	}

	to[n - 1] = n - 1;
	for(int i = n - 2; i >= 0; i--){
		to[i] = i + 1;
		while(to[to[i]] != to[i] && check(ar[i], ar[to[i]], ar[to[to[i]]])){
			to[i] = to[to[i]];
		}
	}

	for(int i = 0; i < n - 1; i++){
		prev[i + 1] = to[i] + 1;
		vec[to[i] + 1].push_back(i + 1);
	}

	dfs(n);

	prev[n] = 0;
	for(int i = 1; i < n; i++){
		up[0][i] = prev[i];
		dbg cout << prev[i] << " ";
	}
	dbg cout << endl;

	for(int i = 1; i < MAX_LOG; i++){
		for(int j = 1; j <= n; j++){
			up[i][j] = up[i - 1][up[i - 1][j]];
			dbg if(up[i][j]){
				cout << i << " " << j << " " << up[i][j] << endl;
			}
		}
	}

	int m;
	cin >> m;
	while(m--){
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << " ";
	}

}