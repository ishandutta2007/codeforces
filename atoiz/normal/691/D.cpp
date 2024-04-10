#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000007;
vector<int> gr[MAX], pos, val;
int n, m, a[MAX];
bool vis[MAX];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

	memset(vis, 0, sizeof vis);
	pos.reserve(n), val.reserve(n);
    for (int u = 1; u <= n; ++u) {
		if (vis[u]) continue;
        pos.clear(); val.clear();
		vis[u] = 1;

        stack<int> st;
        st.push(u);
        while (!st.empty()) {
            int v = st.top(); st.pop();
            pos.push_back(v);
            val.push_back(a[v]);
            for (int w : gr[v]) {
                if (!vis[w]) { vis[w] = 1, st.push(w); }
            }
        }

        sort(pos.begin(), pos.end());
        sort(val.begin(), val.end());

        for (int i = 0; i < (int)pos.size(); ++i) {
            a[pos[i]] = val[pos.size() - i - 1];
        }
    }

    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
}