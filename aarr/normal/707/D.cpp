#include <iostream>
#include <vector>
using namespace std;

const int N = 1005, Q = 100 * 1000 + 5;
int n, m, q;


int ans[Q], sm, cnt[N];
bool b[Q][N], lz[N];
vector <int> adj[Q];
int x[Q], y[Q], qt[Q];

void dfs(int v) {
	int i = x[v], j = y[v];
	int prsm = sm, prlz = lz[i], prcnt = cnt[i];
	bool prb = b[i][j];
	if (qt[v] == 1) {
		if ((lz[i] == 0 && !b[i][j]) || (lz[i] == 1 && b[i][j])) {
			b[i][j] ^= 1;
			cnt[i]++;
			sm++;
		}
	}
	if (qt[v] == 2) {
		if ((lz[i] == 0 && b[i][j]) || (lz[i] == 1 && !b[i][j])) {
			b[i][j] ^= 1;
			cnt[i]--;
			sm--;
		}		
	}
	if (qt[v] == 3) {
		lz[i] ^= 1;
		sm -= cnt[i];
		cnt[i] = m - cnt[i];
		sm += cnt[i];
	}
	
	ans[v] = sm;
	for (auto u : adj[v]) {
		dfs(u);
	}
	sm = prsm, lz[i] = prlz, cnt[i] = prcnt, b[i][j] = prb;
}

int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= q; i++) {
		cin >> qt[i] >> x[i];
		if (qt[i] < 3) {
			cin >> y[i];
		}
		if (qt[i] == 4) {
			adj[x[i]].push_back(i);
		}
		else {
			adj[i - 1].push_back(i);
		}
	}
	dfs(0);
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}