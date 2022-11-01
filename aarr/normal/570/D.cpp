#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;


const int N = 500 * 1000 + 5;
int tm = 1;


vector <int> chld[N];
vector <pair <int, int> > t[N];
int sz[N];
int cnt[N];
int h[N];
int st[N];
int ft[N];
int rl[N];
bool ans[N];
string s;


void pdfs(int v) {
	sz[v] = 1;
	st[v] = tm;
	rl[tm] = v;
	tm++;
	for (auto u : chld[v]) {
		h[u] = h[v] + 1;
		pdfs(u);
		sz[v] += sz[u];
	}
	ft[v] = tm;
}
void dfs(int v) {
//	cout << "71 " << v << endl;
	int bg = 0;
	for (auto u : chld[v]) {
		if (sz[u] > sz[bg]) {
			bg = u;
		}
	}
	
	for (auto u : chld[v]) {
		if (u != bg) {
			dfs(u);
			for (int i = st[u]; i < ft[u]; i++) {
				cnt[h[rl[i]]] = 0;
			}
		}
	}
	if (bg) {
		dfs(bg);
	}
//	vec[v].push_back(v);
	cnt[h[v]] ^= (1 << (s[v - 1] - 'a'));
	for (auto u : chld[v]) {
		if (u != bg) {
			for (int i = st[u]; i < ft[u]; i++) {
				int x = rl[i];
				cnt[h[x]] ^= (1 << (s[x - 1] - 'a'));
			}
		}
	}
	for (auto p : t[v]) {
		if (__builtin_popcount(cnt[p.first]) <= 1) {
			ans[p.second] = true;
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int v;
		cin >> v;
		chld[v].push_back(i);
	}
	pdfs(1);
	cin >> s;
//	for (int i = 1; i <= n; i++) {
//		cout << i << " " << st[i] << " " << ft[i] << endl;
//	}
	for (int i = 0; i < q; i++) {
		int v, h;
		cin >> v >> h;
		h--;
		t[v].push_back({h, i});
	}
	dfs(1);
	for (int i = 0; i < q; i++) {
		if (ans[i]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}