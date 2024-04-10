#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 100 * 1000 + 5;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
long long d[MAXN];
pair<int, int> rail[MAXN];
char r[MAXN];
vector< pair<int, int> > g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        g[v].push_back(make_pair(u, w));
        g[u].push_back(make_pair(v, w));
    }
    for(int i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;
    for(int i = 0; i < k; i++) {
        cin >> rail[i].first >> rail[i].second;
        rail[i].first--;
        d[rail[i].first] = min(d[rail[i].first], (long long)rail[i].second);
        r[rail[i].first] = true;
    }
    set< pair<long long, int> > st;
    for(int i = 0; i < n; i++)
        st.insert(make_pair(d[i], i));
    while(!st.empty()) {
        int v = st.begin()->second;
        st.erase(st.begin());
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = g[v][i].first, w = g[v][i].second;
            if(d[u] >= d[v] + w) {
                st.erase(make_pair(d[u], u));
                d[u] = d[v] + w;
                r[u] = false;
                st.insert(make_pair(d[u], u));
            }
        }
    }
    int ans = k;
    for(int i = 0; i < n; i++)
        if(r[i])
            ans--;
    cout << ans << '\n';
    return 0;
}