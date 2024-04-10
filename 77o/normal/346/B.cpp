#include <bits/stdc++.h>

using namespace std;

using ll = int;

struct FlowEdge {
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e9;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, int cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow() {
        int f = 0;
		for (auto& edge : edges) {
			edge.flow = 0;
		}
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

const int N = 105;

int dp[N][N][N];
int way[N][N][N];
int nxt[N][26];

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s, t, virus;
	cin >> s >> t >> virus;
	for (int i = 0; i < virus.length(); i++) {
		string t = virus.substr(0, i);
		for (char c = 'A'; c <= 'Z'; c++) {
			t += c;
			for (int j = 0; j < t.length(); j++) {
				int len = t.length() - j;
				if (t.substr(j) == virus.substr(0, len)) {
					nxt[i][c - 'A'] = len;
					break;
				}
			}
			t.pop_back();
		}
	}
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 1; j <= t.length(); j++) {
			for (int k = 0; k < virus.length(); k++) {
				if (dp[i - 1][j][k] > dp[i][j - 1][k]) {
					way[i][j][k] = 1;
				} else {
					way[i][j][k] = 2;
				}
				dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
				if (s[i - 1] == t[j - 1]) {
					for (int prev = 0; prev < virus.length(); prev++) {
						if (nxt[prev][s[i - 1] - 'A'] == k && dp[i - 1][j - 1][prev] + 1 > dp[i][j][k]) {
							dp[i][j][k] = dp[i - 1][j - 1][prev] + 1;
							way[i][j][k] = (prev + 1) * 1000;
						}
					}
				}
			}
		}
	}
	int best = 0;
	int ind = -1;
	for (int k = 0; k < virus.length(); k++) {
		if (dp[s.length()][t.length()][k] > best) {
			best = dp[s.length()][t.length()][k];
			ind = k;
		}
	}
	if (best == 0) {
		cout << "0\n";
		return 0;
	}
	int x = s.length();
	int y = t.length();
	string ans;
	while (dp[x][y][ind]) {
		if (way[x][y][ind] == 1) {
			x--;
		} else if (way[x][y][ind] == 2) {
			y--;
		} else {
			ind = way[x][y][ind] / 1000 - 1;
			x--;
			y--;
			ans += s[x];
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}