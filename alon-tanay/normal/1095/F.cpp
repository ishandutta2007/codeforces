#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
using ll = long long;
using pi = pair<ll,ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> as(n);
    for(ll &a : as) { cin >> a; }
    vector<pi> nodes(n);
    for(int i = 0; i < n; i ++) {
        nodes[i] = {as[i],i};
    }
    vector<vector<pi>> nei(n);
    for(int i = 0; i < m; i ++) {
        ll x, y, m;
        cin >> x >> y >> m; x--; y--;
        nei[x].push_back({m,y});
        nei[y].push_back({m,x});
    }
    sort(nodes.begin(),nodes.end());
    int st = nodes[0].s;
    vector<bool> vis(n);
    set<pi> remain;
    for(int i = 0; i < n; i ++) {
        if(i == st) { continue; }
        remain.insert({as[i],i});
    }
    priority_queue<pi,vector<pi>,greater<pi>> es;
    vis[st] = true;
    ll res = 0;
    for(pi ne : nei[st]) {
        es.push(ne);
    }
    for(int i = 1; i < n; i ++) {
        ll nxt = remain.begin()->s;
        ll d = as[nxt] + as[st];
        while(es.size()) {
            pi cur = es.top();
            if(!vis[cur.s]) {
                if(cur.f < d) {
                    nxt = cur.s;
                    d = cur.f;
                    es.pop();
                }
                break;
            }
            es.pop();
        }
        vis[nxt] = true;
        res += d;
        remain.erase({as[nxt],nxt});
        for(pi ne : nei[nxt]) {
            es.push(ne);
        }
    }
    cout << res;
    return 0;
}