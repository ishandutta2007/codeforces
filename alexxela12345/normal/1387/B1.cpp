#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

struct edge{
	int to, ind;
};

const int N = 1e5 + 10;
int n;
vector<edge> g[N];

void read() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
}

const int INF = -1e9;
int dp[N][3];
int par[N][3];

void calcDepth0(int v, int p) {
	dp[v][0] = 0;
	for (auto [i, ind] : g[v]) {
		if (i == p) continue;
		dp[v][0] += max(dp[i][1], dp[i][2]) + 1;
	}
	if (dp[v][0] < 0) {
		dp[v][0] = INF;
	}
}

void relax(int v, int depth, int newVal, int fpar) {
	if (newVal < 0) return;
	if (dp[v][depth] >= newVal) return;
	dp[v][depth] = newVal;
	par[v][depth] = fpar;
}

pair<int, int> q[N];
int topQ;

void calcDepth1(int v, int p) {
	dp[v][1] = INF;
	topQ = 0;
	int sum = 0;
	for (auto [i, ind] : g[v]) {
		if (i == p) continue;
		q[topQ++] = {i, ind};
		sum += max(dp[i][1], dp[i][2]) + 1;
	}
	sort(q, q + topQ, [&] (pair<int, int> a, pair<int, int> b){
		return dp[a.first][0] - dp[a.first][1] > dp[b.first][0] - dp[b.first][1];
	});
	for (int i = 0; i < topQ; i++) {
		sum -= max(dp[q[i].first][1], dp[q[i].first][2]) + 1;
		sum += dp[q[i].first][0];
		relax(v, 1, sum, i);
	}
}

void calcDepth2(int v, int p) {
	dp[v][2] = INF;
	int sum = 0;
	for (auto [i, ind] : g[v]) {
		if (i == p) continue;
		sum += max(dp[i][1], dp[i][2]) + 1;
	}
	for (auto [i, ind] : g[v]) {
		if (i == p) continue;
		sum -= max(dp[i][1], dp[i][2]) + 1;
		relax(v, 2, sum + dp[i][1], i);
		sum += max(dp[i][1], dp[i][2]) + 1;	
	}
	if (dp[v][2] < 0) {
		dp[v][2] = INF;
	}
}

void dfsDp(int v, int p) {
	for (auto [i, ind] : g[v]) {
		if (i == p) continue;
		dfsDp(i, v);
	}
	
	calcDepth0(v, p);
	calcDepth1(v, p);
	calcDepth2(v, p);
}

int ans;
int fans[N];
int used[N];
//int cnt = 0;

void makeUsed(int v, int p, int depth) {
	//cnt++;
	//if (cnt == 10) exit(0);
	//cout << "v = " << v << " p = " << p << " depth = " << depth << " dp = " << dp[v][depth] << endl;
	if (depth == 0) {
		for (auto [i, ind] : g[v]) {
			if (i == p) continue;
			used[ind] = true;
			if (dp[i][1] >= dp[i][2]) {
				makeUsed(i, v, 1);
			} else {
				makeUsed(i, v, 2);
			}
		}
	} else if (depth == 1) {
		vector<pair<int, int>> q;
		int topQ = 0;
		for (auto [i, ind] : g[v]) {
			if (i == p) continue;
			q.push_back({i, ind});
			topQ++;
		}
		sort(q.begin(), q.end(), [&] (pair<int, int> a, pair<int, int> b){
			return dp[a.first][0] - dp[a.first][1] > dp[b.first][0] - dp[b.first][1];
		});
		/*cout << "q = " << endl;
		for (int i = 0; i < topQ; i++) {
			cout << q[i].first << " " << q[i].second << endl;
		}
		cout << "par = " << par[v][1] << " " << topQ << endl;*/
		
		//if (v == 2)
		//exit(0);
		
		for (int i = 0; i <= par[v][1]; i++) {
			makeUsed(q[i].first, v, 0);
		}
		for (int i = par[v][1] + 1; i < topQ; i++) {
			used[q[i].second] = true;
			if (dp[q[i].first][1] >= dp[q[i].first][2]) {
				makeUsed(q[i].first, v, 1);
			} else {
				makeUsed(q[i].first, v, 2);
			}
		}
	} else if (depth == 2) {
		for (auto [i, ind] : g[v]) {
			if (i == p) continue;
			if (par[v][2] == i) {
				makeUsed(i, v, 1);
			} else {
				used[ind] = true;
				if (dp[i][1] >= dp[i][2]) {
					makeUsed(i, v, 1);
				} else {
					makeUsed(i, v, 2);
				}		
			}
		}
	}
}

bool usedV[N];
int order[N];
int topOrder;

void dfsFans(int v, int p) {
	usedV[v] = true;
	order[topOrder++] = v;
	for (auto [i, ind] : g[v]) {
		if (i == p) continue;
		if (used[ind]) continue;
		dfsFans(i, v);
	}
}

void makeAns() {
	ans = 2 * (n - 1) - max(dp[0][1], dp[0][2]) * 2;
	if (dp[0][1] >= dp[0][2]) {
		makeUsed(0, -1, 1);
	} else {
		makeUsed(0, -1, 2);
	}
	/*cout << "used = " << endl;
	for (int i = 0; i < n - 1; i++) {
		cout << used[i] << " ";
	}
	cout << endl;*/
	for (int i = 0; i < n; i++) {
		if (usedV[i]) continue;
		topOrder = 0;
		dfsFans(i, -1);
		assert(topOrder >= 2);
		for (int j = 0; j < topOrder; j++) {
			fans[order[j]] = order[(j + 1) % topOrder];
		}
	}
}

void run() {
	dfsDp(0, 0);
	//cout << "dp = " << endl;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	//return;
	makeAns();
}

void write() {
	cout << ans << endl;
	//return;
	for (int i = 0; i < n; i++) {
		cout << fans[i] + 1 << " ";
	}
	cout << endl;
} 

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	read();
	run();
	write();
	return 0;
}

/*

5
1 2
2 3
3 4
3 5

*/