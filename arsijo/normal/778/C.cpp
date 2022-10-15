#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 9;
const ld E = 1e-7;
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
#define M_PI acos(-1)
#define remove tipa_remove
#define left tipa_left
#define right tipa_right
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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n;

const int MAX = 6e5 + 10;
int vec[MAX][26];

int sz;

int down[MAX];
int d[MAX];

void dfs1(int pos) {
	down[pos] = 1;
	for (int i = 0; i < 26; i++) {
		if (!vec[pos][i])
			continue;
		d[vec[pos][i]] = d[pos] + 1;
		dfs1(vec[pos][i]);
		down[pos] += down[vec[pos][i]];
	}
}

int res[MAX];

vector<pair<int, int> > poses;

void add(int p1, int p2) {
	for(int i = 0; i < 26; i++){
		if(vec[p1][i]){
			if(!vec[p2][i]){
				vec[p2][i] = ++sz;
				poses.push_back(make_pair(p2, i));
			}
			add(vec[p1][i], vec[p2][i]);
		}
	}
}

void dfs2(int pos) {
	vector<ii> v;
	for (int i = 0; i < 26; i++) {
		if (vec[pos][i]) {
			dfs2(vec[pos][i]);
			v.push_back(make_pair(down[vec[pos][i]], vec[pos][i]));
		}
	}
	if(v.empty())
		return;
	sort(v.rbegin(), v.rend());
	sz = n;
	int sz = down[pos] - 1;
	sz -= down[v[0].second] - 1;
	for(int i = 1; i < (int) v.size(); i++){
		add(v[i].second, v[0].second);
	}
	sz -= (int) poses.size();
	while(!poses.empty()){
		vec[poses.back().first][poses.back().second] = 0;
		poses.pop_back();
	}
	res[d[pos]] += sz;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	for(int i = 1; i < n; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		vec[a][c - 'a'] = b;
	}

	dfs1(1);
	dfs2(1);

	int ans1 = -1, ans2 = -1;
	for(int i = 0; i < MAX; i++){
		if(ans1 < res[i]){
			ans1 = res[i];
			ans2 = i + 1;
		}
	}

	cout << n - ans1 << endl << ans2 << endl;

}