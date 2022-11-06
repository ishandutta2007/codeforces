#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 100011;
const int maxVal = 10000011;
const int limit = 10000001;
const int maxLog = 20;
const ll mod = 1000000007;

struct query {
    int x, y, val, lca;
};

int n, q, i, x, y, bg[maxN], en[maxN], cnt;
vector<int> list[maxN];
int dad[maxLog][maxN];
int a[maxN], lvl[maxN];
query Q[maxN];

vector<int> to_add[maxVal];
vector<int> to_query[maxVal];
vector< pair<int, int> > comp;
vector<ll> primes;
bool ciur[maxVal];

int fenw[maxN];
int ans[maxN];



int zrs(int x) {
    return (x ^ (x - 1)) & x;
}

void add(int pos, int val) {
    while (pos <= n) {
        fenw[pos] += val;
        pos += zrs(pos);
    }
}

int sum(int pos) {
    int ans = 0;

    while (pos > 0) {
        ans += fenw[pos];
        pos -= zrs(pos);
    }
    return ans;
}

void dfs(int node, int root) {
    bg[node] = ++cnt;
    for (auto to : list[node]) {
        if (to == root) continue;
        lvl[to] = lvl[node] + 1;
        dad[0][to] = node;
        dfs(to, node);
    }
    en[node] = cnt;
}

void precomp() {
    ll i, j;

    for (i = 1; i < maxLog; i++)
        for (j = 1; j <= n; j++)
            dad[i][j] = dad[i - 1][dad[i - 1][j]];

    for (i = 2; i <= limit; i++) {
        if (ciur[i]) continue;
        primes.pb(i);
        for (j = i * i; j <= limit; j += i) 
            ciur[j] = true;
    }
}

void decompose(ll v) {
    pair<int, int> aux;
    comp.clear();

    //cerr << v << "?!?\n";

    for (ll d : primes) {
        if (d * d > v) break;
        if (v % d) continue;
        
        aux = mp(d, 0);
        while (v % d == 0) {
            aux.second++;
            v /= d;
        }
        comp.pb(aux);
    }

    if (v != 1) comp.pb(mp(v, 1));
}

void add_comp(vector<int> *data, int id, bool forced = false) {
    int i, aux;

    for (auto act : comp) {
        aux = act.first;
        for (i = 1; i <= act.second; i++) {
            if (!forced || i == act.second) {
                data[aux].pb(id);
                //cerr << aux << ' ' << id << '\n';
            }
            aux *= act.first;
        }
    }

    /*for (auto e : comp) {
        cerr << "(" << e.first << ", " << e.second << ") ";
    }
    cerr << "\n";*/
}

void lift_up(int &x, int cnt) {
    int i;

    for (i = 0; cnt > 0; i++, cnt >>= 1)
        if (cnt & 1)
            x = dad[i][x];
}

int get_lca(int x, int y) {
    if (lvl[x] < lvl[y]) swap(x, y);
    lift_up(x, lvl[x] - lvl[y]);
    
    if (x == y) return x;
    for (int i = maxLog - 1; i >= 0; i--)
        if (dad[i][x] != dad[i][y])
            x = dad[i][x], y = dad[i][y];

    return dad[0][x];
}

ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

void solve() {
    ll i, j, act;

    for (i = 2; i <= limit; i++) {
        if (ciur[i]) continue;
        
        for (j = i; j <= limit; j *= i) {
            for (auto e : to_add[j]) {
                add(bg[e], +1);
                add(en[e] + 1, -1);
            }

            for (auto e : to_query[j]) {
                act = sum(bg[Q[e].x]) + sum(bg[Q[e].y]) - sum(bg[Q[e].lca]) - sum(bg[dad[0][Q[e].lca]]);
                //cerr << "!" << i << ' ' << j << ' ' << act  << '\n';
                if (act > 0) ans[e] = (1LL * ans[e] * poww(i, act)) % mod;
            }

            to_query[j].clear();
        }  


        for (j = i; j <= limit; j *= i) {
            for (auto e : to_add[j]) {
                add(bg[e], -1);
                add(en[e] + 1, +1);
            }
        }  

    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1, 0);
    precomp();

    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        decompose(a[i]);
        add_comp(to_add, i);
    }

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d%d", &Q[i].x, &Q[i].y, &Q[i].val);
        Q[i].lca = get_lca(Q[i].x, Q[i].y);
        decompose(Q[i].val);

        /*for (auto e : comp) {
            cerr << e.first << ' ' << e.second << '\n';
        }
        cerr << "\n\n";*/

        add_comp(to_query, i, true);
        ans[i] = 1;
    }

    solve();

    for (i = 1; i <= q; i++) {
        if (ans[i] < 0) exit(-1);
        printf("%d\n", ans[i]);
    }

    return 0;
}