#include<bits/stdc++.h>
using namespace std;

const int N = 2005;

int n;
int n1, l1, tin1[N], tout1[N], up1[22][N], timer1 = 0;
int d1[N], d2[N], p1[N], p2[N];
vector<int> g1[N];
int dp[N][N];

int n2, l2, tin2[N], tout2[N], up2[22][N], timer2 = 0;
vector<int> g2[N];

void dfs1(int u, int c) {
    d1[u] = c;
	tin1[u] = ++timer1;
	for (auto v : g1[u]) {
		dfs1(v, c + 1);
	}
	tout1[u] = timer1;
}

bool isAncestor1(int u, int v) {
	return (tin1[u] <= tin1[v] && tout1[u] >= tout1[v]);
}

int lca1(int u, int v) {
	if (isAncestor1(u, v)) return u;
	if (isAncestor1(v, u)) return v;
	for (int i = l1; i >= 0; i--) {
		if (!isAncestor1(up1[i][u], v)) {
			u = up1[i][u];
		}
	}
	return up1[0][u];
}

void dfs2(int u, int c) {
	tin2[u] = ++timer2;
    d2[u] = c;
	for (auto v : g2[u]) {
		dfs2(v, c + 1);
	}
	tout2[u] = timer2;
}

bool isAncestor2(int u, int v) {
	return (tin2[u] <= tin2[v] && tout2[u] >= tout2[v]);
}

int lca2(int u, int v) {
	if (isAncestor2(u, v)) return u;
	if (isAncestor2(v, u)) return v;
	for (int i = l2; i >= 0; i--) {
		if (!isAncestor2(up2[i][u], v)) {
			u = up2[i][u];
		}
	}
	return up2[0][u];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
    cin >> n1;
    l1 = ceil(log2(n1)) + 1;
    for (int i = 2; i <= n1; i++) {
        int u;
        cin >> u;
        g1[u].push_back(i);
        up1[0][i] = u;
    }
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= n1; j++) {
            up1[i][j] = up1[i - 1][up1[i - 1][j]];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> p1[i];
    }
    g1[0].push_back(1);
    dfs1(0, -1);
    cin >> n2;
    l2 = ceil(log2(n2)) + 1;
    for (int i = 2; i <= n2; i++) {
        int u;
        cin >> u;
        g2[u].push_back(i);
        up2[0][i] = u;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p2[i];
    }
    for (int i = 1; i <= l2; i++) {
        for (int j = 1; j <= n2; j++) {
            up2[i][j] = up2[i - 1][up2[i - 1][j]];
        }
    }
    g2[0].push_back(1);
    dfs2(0, -1);
    dp[1][0] = d1[p1[1]];
    dp[0][1] = d2[p2[1]];
    //cout << lca1(8, 9) << endl;
    for (int i = 2; i <= n; i++) {
        //dp[i][i - 1]
        dp[i][i - 1] = dp[0][i - 1] + d1[p1[i]];
        for (int j = 1; j < i - 1; j++) {
            int u = d1[p1[i]];
            u -= d1[lca1(p1[i], p1[j])];
            dp[i][i - 1] = min(dp[j][i - 1] + u, dp[i][i - 1]);
        }
        //dp[i - 1][i]
        dp[i - 1][i] = dp[i - 1][0] + d2[p2[i]];
        for (int j = 1; j < i - 1; j++) {
            int u = d2[p2[i]];
            u -= d2[lca2(p2[i], p2[j])];
            dp[i - 1][i] = min(dp[i - 1][j] + u, dp[i - 1][i]);
        }
        for (int j = 0; j < i - 1; j++) {
            int u = d1[p1[i]] - d1[lca1(p1[i], p1[i - 1])];
            //if (i == 2 && j == 0) cout << p1[i] << ' ' << p1[i - 1] << endl;
            dp[i][j] = u + dp[i - 1][j];
            u = d2[p2[i]] - d2[lca2(p2[i], p2[i -1])];
            dp[j][i] = u + dp[j][i - 1];
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         cout << i << ' ' << j << " ::";
    //         //cout << dp[i][j] << ' ' << dp[j][i] << endl;
    //     }
    // }
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
        mn = min(mn, dp[i][n]);
        mn = min(mn, dp[n][i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            //cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << dp[j][i] << '\n';
        }
    }
    cout << n1 + n2 - mn - 2;
	return 0;
}