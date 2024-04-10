#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int tin[maxn];
int tout[maxn];
int timer;
ll d[maxn];
vector<int> g[maxn];
void dfs(int v, int pa) {
    d[v] = d[pa] + 1;
    tin[v] = timer++;
    for(int to: g[v]) {
        if(to != pa) {
            dfs(to, v);
        }
    }
    tout[v] = timer - 1;
}
pair<ll, ll> t[4*maxn];
pair<ll, ll> u[4*maxn];
pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b) {
    return make_pair((a.first + b.first) % mod, (a.second + b.second) % mod);
}
void add(int v, pair<ll, ll> x) {
    u[v] = merge(u[v], x);
    t[v] = merge(t[v], x);
}

void push(int v, int l, int r) {
    if(l == r) return;
    add(v*2, u[v]);
    add(v*2+1, u[v]);
    u[v] = make_pair(0, 0);
}
pair<ll, ll> get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(tl > r || l > tr) return make_pair(0, 0);
    if(l <= tl && tr <= r) return t[v];
    int mid = (tl + tr)/2;
    return merge(get(v * 2, tl, mid, l, r), get(v*2+1, mid + 1, tr, l, r));
}
void upd(int v, int tl, int tr, int l, int r, pair<ll, ll> x) {
    push(v, tl, tr);
    if(tl > r || l > tr) return;
    if(l <= tl && tr <= r) {
        add(v, x);
        return;
    }
    int mid = (tl + tr)/2;
    upd(v * 2, tl, mid, l, r, x);
    upd(v*2+1, mid + 1, tr, l, r, x);
    t[v] = merge(t[v*2], t[v*2+1]);
}

void solve(){
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].emplace_back(i);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int type;

        cin >> type;
        if(type == 1) {
            int v, x, k;
            cin >> v >> x >> k;
            upd(1, 0, n-1, tin[v], tout[v], make_pair((x + d[v] * 1ll * k) % mod, k));
        } else {
            int v;
            cin >> v;
            pair<ll, ll> cur = get(1, 0, n-1, tin[v], tin[v]);
            cout << (cur.first - cur.second * d[v] % mod + mod) % mod << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}