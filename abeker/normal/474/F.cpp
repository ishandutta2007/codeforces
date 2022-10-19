#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> par;

const int MAXN = 100005;
const int MAXL = 20;
const int INF = 0x3f3f3f3f;

int N, T;
int s[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d", s + i);
}

int f[MAXL][MAXN];
int g[MAXL][MAXN];
par p[MAXN];
int exp[MAXN];

void init() {
	for (int i = 2; i <= N; i++) 	
		exp[i] = exp[i / 2] + 1;
		
	for (int i = 0; i < N; i++) 
		f[0][i] = s[i];
	for (int i = 0; 1 << i <= N; i++) 
		for (int j = 0; j < N; j++) 
			f[i + 1][j] = min(f[i][j], j + (1 << i) < N ? f[i][j + (1 << i)] : INF);
	
	for (int i = 0; i < N; i++) 
		g[0][i] = s[i];
	for (int i = 0; 1 << i <= N; i++)
		for (int j = 0; j < N; j++) 
			g[i + 1][j] = __gcd(g[i][j], j + (1 << i) < N ? g[i][j + (1 << i)] : 0);		
	
	for (int i = 0; i < N; i++) 
		p[i] = par(s[i], i);
	sort(p, p + N);
}

inline int get_f(int lo, int hi) {
	int e = exp[hi - lo];
	return min(f[e][lo], f[e][hi - (1 << e)]);
}

inline int get_g(int lo, int hi) {
	int e = exp[hi - lo];
	return __gcd(g[e][lo], g[e][hi - (1 << e)]);
}

inline int get_cnt(int lo, int hi, int val) {
	return upper_bound(p, p + N, par(val, hi - 1)) - lower_bound(p, p + N, par(val, lo)); 
}

int query(int lo, int hi) {
	int mini = get_f(lo, hi);
	int div = get_g(lo, hi);
	return div % mini ? hi - lo : hi - lo - get_cnt(lo, hi, mini);
}

void solve() {		
	scanf("%d", &T);
	while (T--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(--l, r));
	}
}

int main() {
	load();
	init();
	solve();
	return 0;
}