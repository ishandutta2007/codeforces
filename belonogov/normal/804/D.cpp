#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = 1e5 + 10;
const ll INF = 1.01e9;
typedef vector<int> vi;

int n, m, q;
vector<int> e[N];
int color[N];
int depth[N];
int res[N];
int dim[N];
vector<int> d[N];
vector<ll> pref[N];
vector<int> comp;
int bestDim;
pair<int,int> query[N];

void dfs1(int v, int c) {
    color[v] = c;
    comp.pb(v);
    depth[v] = 0;
    for (auto u: e[v]) {
        if (color[u] == -1) {
            dfs1(u, c);
            depth[v] = max(depth[v], depth[u] + 1);
        }
    }
}


void dfs2(int v, int p, int top) {
    res[v] = max(top, depth[v]);
    pair<int, int> mx1 = {0, -1};
    pair<int, int> mx2 = {0, -1};
    for (auto u: e[v]) {
        if (u == p) continue;
        pair<int,int> tmp = {depth[u] + 1, u};
        if (tmp > mx2) {
            mx2 = tmp;
            if (mx2 > mx1) {
                swap(mx2, mx1);
            }
        }
    }    
    bestDim = max(bestDim, top + mx1.F);
    bestDim = max(bestDim, mx2.F + mx1.F);

    for (auto u: e[v]) {
        if (u == p) continue;
        if (mx1.S == u) {
            dfs2(u, v, max(top, mx2.F) + 1);
        }
        else  {
            dfs2(u, v, max(top, mx1.F) + 1);
        }
    }
}


void read() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;    
        e[v].pb(u);
        e[u].pb(v);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &query[i].F, &query[i].S);
        query[i].F--;
        query[i].S--;
    }
}

void solve() {
    srand(time(NULL));
    int cur = 0;
    memset(color, -1, sizeof color);
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i;
    random_shuffle(all(perm));
    for (int t = 0; t < n; t++) {
        int i = perm[t];
        //db(i);
        if (color[i] == -1) {
            comp.clear();
            dfs1(i, cur);
            bestDim = 0;
            dfs2(i, -1, 0);

            for (auto v: comp) {
                d[cur].pb(res[v]);
            }
            dim[cur] = bestDim;
            sort(all(d[cur]));

            pref[cur].pb(0);
            for (auto x: d[cur]) {
                pref[cur].pb(pref[cur].back() + x);
            }
            cur++;
        }
    }   

    //for (int i = 0; i < cur; i++) {
        //cerr << endl;
        //db(dim[i]);
        //for (auto x: d[i])
            //cerr << x << " ";
        //cerr << endl;
        //for (auto x: pref[i])
            //cerr << x << " ";
        //cerr << endl;
    //}



    map<pair<int,int>, double> mem;
    for (int t = 0; t < q; t++) {
        int v = query[t].F;
        int u = query[t].S;
        v = color[v];
        u = color[u];
        if (v > u) {
            swap(v, u);
        }
        if (v == u) {
            puts("-1");
            continue;
        }

        ll cnt = d[v].size() * 1ll * d[u].size();
        if (mem.count({v, u}) == 0) {
            ll sum = pref[v].back() * d[u].size() + pref[u].back() * d[v].size() + cnt;
            //db(sum);
            bool flag = 0;
            if (d[v].size() > d[u].size()) {
                swap(v, u);
                flag = 1;
            }

            ll curDim = max(dim[v], dim[u]);
            for (int i = 0; i < sz(d[v]); i++) {
                int pos = lower_bound(all(d[u]), curDim - d[v][i] - 1) - d[u].begin();
                sum -= pref[u][pos] + pos + pos * d[v][i];
                sum += pos * curDim;
            }

            if (flag) {
                swap(v, u);
            }
            //db2(sum, cnt);
            mem[make_pair(v, u)] = sum * 1.0 / cnt;
        }
        printf("%.17f\n", mem[make_pair(v, u)]);
    }


}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    if (1) {
        read();
        solve();
    }   
    else {
        for (int tt = 0; ; tt++) {
            db(tt);
            //genTest();
            //auto r1 = solve();
            //auto r2 = slow();
            //assert(r1 == r2);
        }
    }
            




    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}