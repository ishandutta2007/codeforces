#include <bits/stdc++.h>
using namespace std;

const int MAX = 300007;
int n, p;
vector<int> gr[MAX];
int cnt[MAX], deg[MAX];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) ++cnt[ gr[i].size() ];
    for (int i = n; i >= 0; --i) cnt[i] += cnt[i+1];
    for (int i = 1; i <= n; ++i) deg[i] = gr[i].size();

    int64_t ans = 0;
    for (int u = 1; u <= n; ++u) {
		if (deg[u] >= p) { ans += n-1; continue; }

        int cur = cnt[p - deg[u]];
        if (deg[u] >= p - deg[u]) --cur;

        for (int v : gr[u]) {
			if (deg[v] == p - deg[u]) --cur;
			--deg[v];
        }

//        cerr << u << ": " << cur << endl;
        ans += cur;

        for (int v : gr[u]) deg[v] = gr[v].size();
    }

    cout << ans/2;
}