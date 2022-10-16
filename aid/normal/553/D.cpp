#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Frac {
    int p, q;

    Frac() {}

    Frac(int _p, int _q): p(_p), q(_q) {}

    bool operator<(const Frac &f) const {
        return (long long)p * f.q < (long long)f.p * q;
    }

    bool operator==(const Frac &f) const {
        return (long long)p * f.q == (long long)f.p * q;
    }
};

const int MAXN = 100 * 1000 + 5;
char badv[MAXN], badv0[MAXN];
Frac d[MAXN];
vector<int> g[MAXN];
priority_queue<pair<Frac, int>, vector< pair<Frac, int> >,
               greater< pair<Frac, int> > > pq;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int v;
        cin >> v;
        v--;
        badv[v] = true;
        badv0[v] = true;
    }
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        d[i] = Frac(g[i].size(), g[i].size());
    for(int v = 0; v < n; v++)
        if(badv[v]) {
            d[v] = Frac(0, 1);
            for(size_t i = 0; i < g[v].size(); i++)
                if(!badv[g[v][i]])
                    d[g[v][i]].p--;
        }
    for(int i = 0; i < n; i++)
        if(!badv[i])
            pq.push(make_pair(d[i], i));
    Frac ans(0, 1);
    while(!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if(badv[v])
            continue;
        ans = max(ans, d[v]);
        badv[v] = true;
        for(size_t i = 0; i < g[v].size(); i++)
            if(!badv[g[v][i]]) {
                d[g[v][i]].p--;
                pq.push(make_pair(d[g[v][i]], g[v][i]));
            }
    }
    for(int i = 0; i < n; i++)
        badv[i] = badv0[i];
    for(int i = 0; i < n; i++)
        d[i] = Frac(g[i].size(), g[i].size());
    for(int v = 0; v < n; v++)
        if(badv[v]) {
            d[v] = Frac(0, 1);
            for(size_t i = 0; i < g[v].size(); i++)
                if(!badv[g[v][i]])
                    d[g[v][i]].p--;
        }
    for(int i = 0; i < n; i++)
        if(!badv[i])
            pq.push(make_pair(d[i], i));
    while(!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if(badv[v])
            continue;
        if(d[v] == ans)
            break;
        badv[v] = true;
        for(size_t i = 0; i < g[v].size(); i++)
            if(!badv[g[v][i]]) {
                d[g[v][i]].p--;
                pq.push(make_pair(d[g[v][i]], g[v][i]));
            }
    }
    int sz = 0;
    for(int i = 0; i < n; i++)
        if(!badv[i])
            sz++;
    cout << sz << '\n';
    for(int i = 0; i < n; i++)
        if(!badv[i])
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}