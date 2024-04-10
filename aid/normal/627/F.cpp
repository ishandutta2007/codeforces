#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int a[MAXN], b[MAXN], p[MAXN];
char onCycle[MAXN];
vector<int> g[MAXN];

void dfs(int v) {
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p[v]) {
            p[g[v][i]] = v;
            dfs(g[v][i]);
        }
}

long long solve(vector<int> cycle, vector<int> a, vector<int> b) {
    size_t s = 0;
    while(a[s])
        s++;
    long long res = 0;
    while(b[s]) {
        size_t nxt = (s + 1) % cycle.size();
        swap(a[s], a[nxt]);
        s = nxt;
        res++;
    }
    a.erase(a.begin() + s);
    b.erase(b.begin() + s);
    int sh = 0;
    while(b[sh] != a[0])
        sh++;
    res += (long long)min(sh, (int)a.size() - sh) * (long long)cycle.size();
    rotate(b.begin(), b.begin() + sh, b.end());
    if(a != b)
        return -1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int s = -1, t = -1;
    for(int i = 0; i < n; i++) {
        if(!a[i])
            s = i;
        if(!b[i])
            t = i;
    }
    p[t] = -1;
    dfs(t);
    vector< pair<int, int> > st;
    while(s != t) {
        st.push_back(make_pair(s, p[s]));
        swap(a[s], a[p[s]]);
        s = p[s];
    }
    for(int i = 0; i < n; i++)
        if(a[i] != b[i]) {
            onCycle[i] = true;
            onCycle[p[i]] = true;
        }
    vector<int> leaves;
    for(int i = 0; i < n; i++)
        if(onCycle[i]) {
            int deg = 0;
            for(size_t j = 0; j < g[i].size(); j++)
                if(onCycle[g[i][j]])
                    deg++;
            if(deg != 1 && deg != 2) {
                cout << -1 << '\n';
                return 0;
            }
            if(deg == 1)
                leaves.push_back(i);
        }
    if(leaves.size() > 2) {
        cout << -1 << '\n';
        return 0;
    }
    if(leaves.empty()) {
        cout << 0 << ' ' << st.size() << '\n';
        return 0;
    }
    if(leaves[0] > leaves[1])
        swap(leaves[0], leaves[1]);
    vector<int> cycle;
    cycle.push_back(leaves[0]);
    while(cycle.back() != leaves[1]) {
        int v = cycle.back();
        for(size_t i = 0; i < g[v].size(); i++)
            if(onCycle[g[v][i]] &&
               (cycle.size() == 1 || cycle[cycle.size() - 2] != g[v][i])) {
                cycle.push_back(g[v][i]);
                break;
            }
    }
    while(!st.empty()) {
        int v = st.back().first, u = st.back().second;
        swap(a[v], a[u]);
        st.pop_back();
    }
    for(int i = 0; i < n; i++)
        if(!a[i])
            s = i;
    int w = -1;
    for(int i = 0; i < n; i++)
        if(onCycle[i] && (p[i] == -1 || !onCycle[p[i]]))
            w = i;
    p[w] = -1;
    dfs(w);
    long long ans = 0;
    while(t != w) {
        swap(b[t], b[p[t]]);
        t = p[t];
        ans++;
    }
    p[s] = -1;
    dfs(s);
    w = -1;
    for(int i = 0; i < n; i++)
        if(onCycle[i] && (p[i] == -1 || !onCycle[p[i]]))
            w = i;
    p[w] = -1;
    dfs(w);
    while(s != w) {
        swap(a[s], a[p[s]]);
        s = p[s];
        ans++;
    }
    vector<int> ca(cycle.size()), cb(cycle.size());
    for(size_t i = 0; i < cycle.size(); i++) {
        ca[i] = a[cycle[i]];
        cb[i] = b[cycle[i]];
    }
    long long ans0 = solve(cycle, ca, cb);
    reverse(cycle.begin(), cycle.end());
    reverse(ca.begin(), ca.end());
    reverse(cb.begin(), cb.end());
    long long ans1 = solve(cycle, ca, cb);
    if(ans0 == -1) {
        if(ans1 == -1)
            ans = -1;
        else
            ans += ans1;
    }
    else {
        if(ans1 == -1)
            ans += ans0;
        else
            ans += min(ans0, ans1);
    }
    if(ans == -1)
        cout << -1 << '\n';
    else
        cout << leaves[0] + 1 << ' ' << leaves[1] + 1 << ' ' << ans << '\n';
    return 0;
}