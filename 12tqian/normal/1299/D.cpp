#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef double db;

template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

const int P = 1e9 + 7;

int mpow(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) {
            r *= b;
            r %= P;
        }
        b *= b; 
        b %= P;
        e >>= 1;
    }
    return r;
}

int minv(int x) { return mpow(x, P - 2); }
int mult(int a, int b) { return 1LL * a * b % P; }
int add(int a, int b) { a += b; if (a >= P) a -= P; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += P; return a; }
int madd(int& a, int b) { return a = add(a, b); }
int mmult(int& a, int b) { return a = mult(a, b); }

const int N = 1e5 + 5;
const int B = 400;

int n, m;

vector<vi> store;

int comb[B][B];

int reduce(vi& b, int x) {
    trav(t, b) {
        ckmin(x, x ^ t);
    }
    return x;
}

bool add(vi& b, int x) {
    if (!(x = reduce(b, x))) return false;
    int ind = 0;
    while (ind < sz(b) && b[ind] > x) ind++;
    b.insert(b.begin() + ind, x);
    return true;
}

vi add_basis(vi& a, vi& b) {
    vi res;
    trav(t, a) {
        add(res, t);
    }
    trav(t, b) {
        add(res, t);
    }
    return res;
}

bool valid(vector<vi> bs) {
    vi basis;
    trav(b, bs) {
        trav(x, b) {
            if (!add(basis, x)) return true;
        }
    }
    return false;
}

void full_reduce(vi& b) {
    int n = sz(b);
    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            ckmin(b[j], b[j] ^ b[i]);
        }
    }
}

template <class T> int get_pos(vector<T>& v, T x) { 
    return lower_bound(all(v), x) - v.begin();
}

void gen() {
    vector<vi> base = {{}}; // empty basis first
    trav(t, base) store.pb(t);
    f1r(i, 1, 6) {
        vector<vi> nbase;
        f0r(j, 32) {
            for (auto t : base) {
                if (add(t, j)) {
                    full_reduce(t);
                    nbase.pb(t);
                }
            }
        }
        base.swap(nbase);
        sort(all(base));
        base.erase(unique(all(base)), base.end());
        trav(t, base) {
            store.pb(t);
        }
    }

    sort(all(store));

    f0r(i, sz(store)) {
        auto& x = store[i];
        f0r(j, sz(store)) {
            auto& y = store[j];
            auto z = add_basis(x, y);
            full_reduce(z);
            if (sz(z) != sz(x) + sz(y)) {
                comb[i][j] = -1;
            } else {
                comb[i][j] = get_pos(store, z);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    gen();

    cin >> n >> m;

    vector<vpi> adj(n);
    vi base(n);
    vi head(n);

    f0r(i, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }

    vi direct;
    trav(t, adj[0]) direct.pb(t.f);
    sort(all(direct));

    vi vis(n);
    vi in(n);
    vi down(n);

    trav(go, adj[0]) {
        vis[0] = 1;
        in[0] = -1;
        int x = go.f;
        head[x] = go.s;
        direct.pb(x);
        vi basis;
        int path = 0;
        bool bad = false;
        vi comp;

        int ti = 0;
        function<void(int, int)> dfs = [&](int u, int p) {
            vis[u] = 1;
            comp.pb(u);
            in[u] = ti++;
            down[u] = path;
            trav(v, adj[u]) {
                if (v.f == p) continue;
                if (v.f == 0) continue;

                if (vis[v.f]) {
                    if (in[v.f] < in[u]) {
                        if (!add(basis, down[u] ^ down[v.f] ^ v.s)) {
                            bad = true;
                        }
                    }
                    continue;
                }

                path ^= v.s;
                dfs(v.f, u);
                path ^= v.s;
            }
        };

        dfs(x, 0);
        trav(t, comp) vis[t] = 0;
        
        if (bad) base[x] = -1;
        else {
            full_reduce(basis);
            base[x] = get_pos(store, basis);
        } 
    }

    sort(all(direct));
    int sz = sz(direct);
    
    set<int> rem;
    trav(t, direct) {
        rem.insert(t);
    }

    vector<vi> use;

    while (sz(rem)) {
        int x = *rem.begin();
        int ot = -1;
        int w;
        rem.erase(x);
        trav(y, adj[x]) {
            if (rem.count(y.f)) {
                ot = y.f;
                w = y.s;
                rem.erase(y.f);
                break;
            }
        }
        vi tmp;
        tmp.pb(0);
        if (ot == -1) {
            if (base[x] != -1) {
                tmp.pb(base[x]);
            }
        } else {
            if (base[x] != -1) {
                tmp.pb(base[x]);
            }
            if (base[ot] != -1) {
                tmp.pb(base[ot]);
            }
            if (base[x] != -1 && base[ot] != -1) {
                int val = head[x] ^ head[ot] ^ w;
                if (val != 0) {
                    int i1 = get_pos(store, {val});
                    int i2 = base[x];
                    int res = comb[i1][i2];
                    if (res != -1) {
                        tmp.pb(res);
                    }
                }
            }
        }
        use.pb(tmp);
    }

    // cout << "DONE" << endl;
    int spaces = sz(store);
    vi dp(spaces);
    vi ndp(spaces);

    dp[0] = 1; 

    trav(t, use) {
        trav(c, t) {
            // trav(v, store[c]) {
            //     cout << v << " ";
            // }
            // cout << endl;
            f0r(p, spaces) {
                if (comb[c][p] != -1) {
                    madd(ndp[comb[c][p]], dp[p]);
                }
            }
        }

        dp.swap(ndp);
        ndp.assign(spaces, 0);
    }

    // cout << " bad" << '\n';
    // return 0;

    int ans = 0;

    trav(t, dp) madd(ans, t);

    cout << ans << '\n';


    return 0;
}