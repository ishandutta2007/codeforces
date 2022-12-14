#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

struct node{
    int t;
    node *l, *r;
    node(): t(0), l(r=nullptr){}
};

ll stn, tin[MAXN], tout[MAXN], kol[MAXN], p[111111][18];
ll N[MAXN];

vector <ll> v[111111], V[111111], VK[111111];
vector <node *> VC[111111];

void dfs(ll x){
    tin[x] = ++stn;
    kol[x] = 1;
    for(auto to : v[x]){
        dfs(to);
        kol[x] += kol[to];
    }
    tout[x] = stn;
}

bool is_less(ll a, ll b){
    if(tin[b] <= tin[a] && tout[a] <= tout[b])return 1;
    return 0;
}

ll lca(ll a, ll b){
    if(is_less(a, b))return b;
    if(is_less(b, a))return a;
    for(int i = 17; i >= 0; i--)if(!is_less(b, p[a][i]))a = p[a][i];
    return p[a][0];
}

ll id;

ll G[MAXN], poz[MAXN], pr[MAXN];

void build_hld(ll x, ll gr){
    G[x] = gr;
    V[gr].p_b(x);
    poz[x] = V[gr].size();
    ll c = -1, ver;
    for(auto to : v[x]){
        if(kol[to] > c){
            c = kol[to];
            ver = to;
        }
    }

    if(kol[x] > 1)build_hld(ver, gr);

    for(auto to : v[x]){
        if(to == ver)continue;
        pr[++id] = x;
        build_hld(to, id);
    }

}

void build(node *v, int tl, int tr){
    if(tl != tr){
        int tm = (tl + tr) >> 1;
        v -> l = new node();
        v -> r = new node();
        build(v -> l, tl, tm);
        build(v -> r, tm + 1, tr);
    }
}

int Val(node *v){
    if(v == nullptr)return 0;
    return v -> t;
}

node *old;

void modify(node *v, int tl, int tr, int pos){
    if(tl == tr)v -> t = 1; else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            old = v -> l;
            v -> l = new node();
            (v -> l) -> l = old -> l;
            (v -> l) -> r = old -> r;
            modify(v -> l, tl, tm, pos);
        }else{
            old = v -> r;
            v -> r = new node();
            (v -> r) -> l = old -> l;
            (v -> r) -> r = old -> r;
            modify(v -> r, tm + 1, tr, pos);
        }
        v -> t = Val(v -> l) + Val(v -> r);
    }
}

int get(node *v, int tl, int tr, int l, int r){
    if(l > r)return 0;
    if(tl == l && tr == r)return v -> t;
    int tm = (tl + tr) >> 1;
    return get(v -> l, tl, tm, l, min(r, tm)) + get(v -> r, tm + 1, tr, max(l, tm + 1), r);
}

node *last[MAXN];

ll ans, k;

void dfs(node *v, node *v1, int tl, int tr){
    if(ans != -1)return;
    if(tr - tl + 1 - v -> t + v1 -> t < k){
        k -= tr - tl + 1 - v -> t + v1 -> t;
        return;
    }
    if(tl == tr){
        ans = tl;
        return;
    }
    int tm = (tl + tr) >> 1;
    dfs(v -> r, v1 -> r, tm + 1, tr);
    dfs(v -> l, v1 -> l, tl, tm);

}

void find(node *v, node *v1, int tl, int tr, int l, int r){
    if(l > r)return;
    if(ans != -1)return;
    if(tl == l && tr == r){
        dfs(v, v1, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    find(v -> r, v1 -> r, tm + 1, tr, max(l, tm + 1), r);
    find(v -> l, v1 -> l, tl, tm, l, min(r, tm));
}

ll del[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll D;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        p[i][0] = x;
        v[x].p_b(i);
        if(!x)D = i;
    }

    tout[0] = 1e18;
    dfs(D);

    for(int j = 1; j < 18; j++)
        for(int i = 1; i <= n; i++)p[i][j] = p[p[i][j - 1]][j - 1];

    build_hld(D, ++id);

    for(int i = 1; i <= id; i++){
        N[i] = V[i].size();
        node *root = new node();
        build(root, 1, N[i]);
        last[i] = root;
        VK[i].p_b(0ll);
        VC[i].p_b(root);
    }

    ll q;
    cin >> q;

    node *rt;

    for(int step = 1; step <= q; step++){
        ll t;
        cin >> t;
        if(t == 1){
            ll x;
            cin >> x;
            node *root = new node();
            root -> l = last[G[x]] -> l;
            root -> r = last[G[x]] -> r;
            modify(root, 1, N[G[x]], poz[x]);
            VK[G[x]].p_b(step);
            VC[G[x]].p_b(root);
            last[G[x]] = root;
            del[x] = step;
        }else{
            ll a, b, y;
            cin >> a >> b >> k >> y;
            ans = -1;
            ll c = lca(a, b), pt, ide;
            if(b == p[a][0] || a == p[b][0]){
                cout << "-1\n";
                continue;
            }
            if(c != a){
                ll x = p[a][0];
                while(1){
                    ide = G[x];
                    pt = upper_bound(all(VK[ide]), y) - VK[ide].begin();
                    rt = VC[ide][pt - 1];
                    ll le = 1, ri = poz[x];
                    if(G[c] == ide){
                        le = poz[c];
                        if(c == b)le++;
                        int sc = ri - le + 1 - get(last[ide], 1, N[ide], le, ri) + get(rt, 1, N[ide], le, ri);
                        if(sc < k){
                            k -= sc;
                            break;
                        }
                        ans = -1;
                        find(last[ide], rt, 1, N[ide], le, ri);
                        ans = V[ide][ans - 1];
                        k = 0;
                        break;
                    }else{
                        int sc = ri - le + 1 - get(last[ide], 1, N[ide], le, ri) + get(rt, 1, N[ide], le, ri);
                        if(sc < k){
                            k -= sc;
                            x = pr[ide];
                            continue;
                        }
                        ans = -1;
                        find(last[ide], rt, 1, N[ide], le, ri);
                        ans = V[ide][ans - 1];
                        k = 0;
                        break;
                    }
                    x = pr[G[x]];
                }
            }

            if(!k){
                cout << ans << "\n";
                continue;
            }

            if(c != b){
                    ll su = 0;
                    ll x = p[b][0];
                    if(c != a && del[c] <= y)k++;
                  while(1){
                    ide = G[x];
                    pt = upper_bound(all(VK[ide]), y) - VK[ide].begin();
                    rt = VC[ide][pt - 1];
                    ll le = 1, ri = poz[x];
                    if(G[c] == ide){
                        le = poz[c];
                        if(c == a)le++;
                        int sc = ri - le + 1 - get(last[ide], 1, N[ide], le, ri) + get(rt, 1, N[ide], le, ri);
                        su += sc;
                        break;
                    }else{
                        int sc = ri - le + 1 - get(last[ide], 1, N[ide], le, ri) + get(rt, 1, N[ide], le, ri);
                        su += sc;
                    }
                    x = pr[G[x]];
                }

                if(su < k){
                    cout << "-1\n";
                    continue;
                }
                k = su - k + 1;
                x = p[b][0];
                 while(1){
                    ide = G[x];
                    pt = upper_bound(all(VK[ide]), y) - VK[ide].begin();
                    rt = VC[ide][pt - 1];
                    ll le = 1, ri = poz[x];
                    if(G[c] == ide){
                        le = poz[c];
                        if(c == a)le++;
                        int sc = ri - le + 1 - get(last[ide], 1, N[ide], le, ri) + get(rt, 1, N[ide], le, ri);
                        if(sc < k){
                            k -= sc;
                            break;
                        }
                        ans = -1;
                        find(last[ide], rt, 1, N[ide], le, ri);
                        ans = V[ide][ans - 1];
                        k = 0;
                        break;
                    }else{
                        int sc = ri - le + 1 - get(last[ide], 1, N[ide], le, ri) + get(rt, 1, N[ide], le, ri);
                        if(sc < k){
                            k -= sc;
                            x = pr[ide];
                            continue;
                        }
                        ans = -1;
                        find(last[ide], rt, 1, N[ide], le, ri);
                        ans = V[ide][ans - 1];
                        k = 0;
                        break;
                    }
                    x = pr[G[x]];
                }
            }

            if(!k)cout << ans << "\n";
            else cout << "-1\n";

        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}