#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 305;
char used[MAXN], del[MAXN];
int a[MAXN], b[MAXN], tin[MAXN], f[MAXN], t, maxv;
vector<int> g[MAXN];
vector< pair<pair<int, int>, int> > ans;

int getNotCut(int v, int p) {
    used[v] = true;
    tin[v] = t++;
    f[v] = t++;
    int cnt = 0;
    bool cut = false;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(u == p || del[u])
            continue;
        if(used[u])
            f[v] = min(f[v], tin[u]);
        else {
            cnt++;
            int w = getNotCut(u, v);
            if(w != -1)
                return w;
            f[v] = min(f[v], f[u]);
            if(p != -1 && f[u] >= tin[v])
                cut = true;
        }
    }
    if(p == -1 && cnt > 1)
        cut = true;
    if(!cut)
        return v;
    return -1;
}

void dfsAdd(int v, int need) {
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(used[u] || del[u])
            continue;
        dfsAdd(u, maxv - a[u]);
        int add = min(need, a[u]);
        a[u] -= add;
        a[v] += add;
        need -= add;
        ans.push_back(make_pair(make_pair(u, v), add));
    }
}

void dfsSub(int v, int need) {
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(used[u] || del[u])
            continue;
        dfsSub(u, a[u]);
        int sub = min(need, maxv - a[u]);
        a[u] += sub;
        a[v] -= sub;
        need -= sub;
        ans.push_back(make_pair(make_pair(v, u), sub));
    }
}

bool fix(int s, int n) {
    while(true) {
        t = 0;
        for(int i = 0; i < n; i++)
            used[i] = false;
        s = getNotCut(s, -1);
        for(int i = 0; i < n; i++)
            used[i] = false;
        if(a[s] < b[s])
            dfsAdd(s, b[s] - a[s]);
        if(a[s] < b[s])
            return false;
        for(int i = 0; i < n; i++)
            used[i] = false;
        if(a[s] > b[s])
            dfsSub(s, a[s] - b[s]);
        if(a[s] > b[s])
            return false;
        del[s] = true;
        for(size_t i = 0; i < g[s].size(); i++)
            if(!del[g[s][i]]) {
                s = g[s][i];
                break;
            }
        if(del[s])
            break;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, e;
    cin >> n >> maxv >> e;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < e; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        if(a[i] != b[i] && !fix(i, n)) {
            cout << "NO\n";
            return 0;
        }
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i].first.first + 1 << ' ' << ans[i].first.second + 1 << ' '
             << ans[i].second << '\n';
    return 0;
}