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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
const int MOD = 1e9 + 7;
const int BASE = 61;

struct Edge {
    int v, u;
    ll c;
};

vector<Edge> edge;
vector<bool> used; 
vector<pair<int, ll>> e[N];
int p[N];
int n, m;
vector<Edge> g[N];
ll answer;
bool use[N];
ll h[N];
ll cntPath[BASE];
vector<int> who;

void dfs0(int v, ll sumXor) {
    use[v] = 1;
    h[v] = sumXor;
    who.pb(v);
    for (auto x: e[v])
        if (!use[x.fr]) {
            dfs0(x.fr, sumXor ^ x.sc);
        }
}


pair<ll, ll> dfs1(int v, int bitId) {
    use[v] = 1;
    pair<ll, ll> st(1, 0); // 0 1
    for (auto x: e[v]) {
        if (!use[x.fr]) {
            auto res = dfs1(x.fr, bitId);
            if ((x.sc >> bitId) & 1)
                swap(res.fr, res.sc);

            cntPath[bitId] += st.fr * res.sc + st.sc * res.fr;
            st.fr += res.fr;
            st.sc += res.sc;
        }
    }
    return st;
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        ll c;
        scanf("%d%d%lld", &v, &u, &c); v--; u--;
        edge.pb({v, u, c});
    }
}

int getId(int v) {
    return (p[v] == v)? v: p[v] = getId(p[v]);
}



int calcSize(vector<ll> b) {
    int cur = 0;
    int k = b.size();
    for (int i = 0; i < BASE; i++) {
        int pos = -1;
        for (int j = cur; j < k; j++) {
            if ((b[j] >> i) & 1)
                pos = j;
        }
        if (pos == -1) continue;
        swap(b[cur], b[pos]);  
        for (int j = 0; j < k; j++) {
            if (j == cur) continue;
            if ((b[j] >> i) & 1)
                b[j] ^= b[cur];
        }
        cur++;
    }
    int cnt = 0;
    for (auto x: b)
        cnt += x != 0;
    return cnt;
}

void myAssert(bool flag) {
    if (!flag) {
        cerr << "!fail" << endl;
        while (true);
    }
}

void solve() {
    answer = 0;
    for (int i = 0; i < n; i++) {
        e[i].clear();
        g[i].clear();
        use[i] = 0;
    }
    //vector<ll> tmp = {1, 2, 4, 8, 5, 6, 2, 3, 6, 9, 128, (1ll << 40) - 1, 79239842934234ll};
    //db(calcSize(tmp));
    //exit(0);


    for (int i = 0; i < n; i++)
        p[i] = i;

    used.assign(m, 0);
    for (int i = 0; i < m; i++) {
        int v = getId(edge[i].v);
        int u = getId(edge[i].u); 
        if (v != u) {
            used[i] = 1;
            p[v] = u;
            e[edge[i].v].pb(mp(edge[i].u, edge[i].c));
            e[edge[i].u].pb(mp(edge[i].v, edge[i].c));
        }
    }

    for (int i = 0; i < m; i++) {
        if (used[i] == 0) {
            int v = getId(edge[i].v);     
            g[v].pb(edge[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (use[i] == 0) {
            who.clear();
            dfs0(i, 0);

            //db(who.size());
            memset(cntPath, 0, sizeof(cntPath));
            for (int t = 0; t < BASE; t++) {
                for (auto v: who)
                    use[v] = 0;
                dfs1(i, t);
            }


            int head = getId(i);
            vector<ll> cycle;
            for (auto x: g[head]) {
                myAssert(use[x.v]);
                myAssert(use[x.u]);
                cycle.pb(x.c ^ h[x.v] ^ h[x.u]);
            }
            //db(cycle.size());
            //for (auto x: cycle)
                //cerr << x << " ";
            //cerr << endl;
            ll sumOr = 0;
            for (auto x: cycle)
                sumOr |= x;


            int cnt = calcSize(cycle);
            //for (int i = 0; i < 10; i++)
                //cerr << cntPath[i] << " ";
            //cerr << endl;
             
            for (int t = 0; t < BASE; t++) {
                ll c0 = who.size() * 1ll * (who.size() - 1) / 2 - cntPath[t];   
                ll c1 = cntPath[t];   
                //db2(c0, c1);
                myAssert(c0 >= 0);
                if ((sumOr >> t) & 1) {
                    myAssert(cnt >= 1);
                    ll tmp = (1ll << t) % MOD;
                    tmp = (tmp * ((c0 + c1) % MOD)) % MOD;
                    tmp = (tmp * ((1ll << (cnt - 1)) % MOD)) % MOD;
                    answer = (answer + tmp) % MOD;
                }
                else {
                    ll tmp = (1ll << t) % MOD;
                    tmp = (tmp * (c1 % MOD)) % MOD;
                    tmp = (tmp * ((1ll << cnt) % MOD)) % MOD;
                    answer = (answer + tmp) % MOD; 
                }
            }
        }        
    }

    printf("%lld\n", answer);
}

void genTest() {
    n = rand() % 100 + 1;
    m = rand() % 200 + 1;
    //int T = 10;
    edge.clear();
    for (int i = 0; i < m; i++) {
        int v = rand() % n;
        int u = rand() % n;
        ll c = ((rand() * 1ll) << 20) + rand();
        if (v == u) 
            v = (v + 1) % n;
        edge.pb({v, u, c});
    }
}

void printTest() {
    cout << n << " " << m << endl;
    for (auto x: edge)
        cout << x.v + 1 << " " << x.u + 1 << " " << x.c << endl;

}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        //printTest();
        solve();

    }

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}