#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int inf = 1e9 + 1;
#define se second
#define fi first
struct seg{
    int l, r, mid, mi = inf;
    seg *ch[2] = {NULL, NULL};
    void modify(seg *pre, int pos, int val){
        if (l == r){
            mi = val;
            return;
        }
        if (pos <= mid){
            ch[0] = new seg(l, mid);
            ch[1] = pre->ch[1];
            ch[0]->modify(pre->ch[0], pos, val);
        }
        else{
            ch[1] = new seg(mid + 1, r);
            ch[0] = pre->ch[0];
            ch[1]->modify(pre->ch[1], pos, val);
        }
        mi = min(ch[0]->mi, ch[1]->mi);
    }
    int query(int _l, int _r){
        if (_l <= l and _r >= r) return mi;
        if (_l > r or _r < l) return inf;
        return min(ch[0]->query(_l, _r), ch[1]->query(_l, _r));
    }
    void init(){
        if (l == r) return;
        ch[0] = new seg(l, mid);
        ch[1] = new seg(mid + 1, r);
        for (auto &i : ch) i->init();
    }
    seg (int _l, int _r){
        l = _l, r = _r, mid = l + r >> 1;
    }
};
int t = 0, ed[N], st[N], depth[N], a[N];
vector<int> g[N];
vector<pair<int, int>> node;
void dfs(int u, int p){
    st[u] = t++;
    for (int i : g[u]) if (i != p) depth[i] = depth[u] + 1, dfs(i, u);
    ed[u] = t++;
    node.push_back({depth[u], u});
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, r, m, last = 0;
    cin >> n >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(r, -1);
    sort(node.begin(), node.end());
    vector<seg*> rt;
    rt.push_back(new seg(0, N));
    rt[0]->init();
    for (int i = 0; i < n; i++){
        rt.push_back(new seg(0, N));
        rt[i + 1]->modify(rt[i], st[node[i].se], a[node[i].se]);
        while(i < n - 1 and node[i].fi == node[i + 1].fi){
            i++;
            rt.push_back(new seg(0, N));
            rt[i + 1]->modify(rt[i], st[node[i].se], a[node[i].se]);
        }
    }
    cin >> m;
    while (m--){
        int p, q;
        cin >> p >> q;
        p = (p + last) % n + 1, q = (q + last) % n;
        int it = upper_bound(node.begin(), node.end(), make_pair(depth[p] + q + 1, -1)) - node.begin();
        last = rt[it]->query(st[p], ed[p]);
        cout << last << '\n';
    }
}