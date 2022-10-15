#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
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
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
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
char wr[12];
int k;
inline void write(int x) {
	k = 0;
	if (!x)
		++k, wr[k] = '0';
	while (x) {
		++k;
		wr[k] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = k; i >= 1; --i)
		putchar(wr[i]);
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 3004;
int dist1[MAX][MAX], dist2[MAX][MAX], n, m;
vector<int> vec1[MAX], vec2[MAX];
bool used[MAX];
queue<int> q;
const int INF = 1e8;
void pre(int pos) {
	for (int i = 1; i <= n; i++)
		dist1[pos][i] = dist2[pos][i] = INF;
	q.push(pos);
	dist1[pos][pos] = 0;
	int p = pos;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (int i = 0; i < (int) vec1[pos].size(); i++) {
			if (dist1[p][vec1[pos][i]] == INF) {
				dist1[p][vec1[pos][i]] = dist1[p][pos] + 1;
				q.push(vec1[pos][i]);
			}
		}
	}
	q.push(pos);
	dist2[pos][pos] = 0;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (int i = 0; i < (int) vec2[pos].size(); i++) {
			if (dist2[p][vec2[pos][i]] == INF) {
				dist2[p][vec2[pos][i]] = dist2[p][pos] + 1;
				q.push(vec2[pos][i]);
			}
		}
	}
}
int Q = 2;
vector<int> v1[MAX], v2[MAX];
void pre2(int pos) {
	ms(used);
	used[pos] = true;
	for (int j = 0; j < Q; j++) {
		int w = -1;
		for (int i = 1; i <= n; i++) {
			if (!used[i] && dist1[pos][i] != INF
					&& (w == -1 || dist1[pos][i] > dist1[pos][w])) {
				w = i;
			}
		}
		if (w == -1)
			break;
		used[w] = true;
		v1[pos].push_back(w);
	}
	ms(used);
	used[pos] = true;
	for (int j = 0; j < Q; j++) {
		int w = -1;
		for (int i = 1; i <= n; i++) {
			if (!used[i] && dist2[pos][i] != INF
					&& (w == -1 || dist2[pos][i] > dist2[pos][w])) {
				w = i;
			}
		}
		if (w == -1)
			break;
		used[w] = true;
		v2[pos].push_back(w);
	}
}

int ans = -1, _a, _b, _c, _d;

inline void upd(int a, int b, int c, int d, int res){
	if(a != b && a != c && a != d && b != c && b != d && c != d && ans < res){
		ans = res;
		_a = a;
		_b = b;
		_c = c;
		_d = d;
	}
}

inline void try_to_upd(int b, int c){
	for(int i = 0; i < (int) v2[b].size(); i++){
		for(int j = 0; j < (int) v1[c].size(); j++){
			upd(v2[b][i], b, c, v1[c][j], dist2[b][v2[b][i]] + dist1[b][c] + dist1[c][v1[c][j]]);
		}
	}
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
	for(int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		vec1[a].push_back(b);
		vec2[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
	pre(i);
	for(int i = 1; i <= n; i++)
	pre2(i);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dist1[i][j] != INF)
			try_to_upd(i, j);
		}
	}

	cout << _a << " " << _b << " " << _c << " " << _d << endl;

}