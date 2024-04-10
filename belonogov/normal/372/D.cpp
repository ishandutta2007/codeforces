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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
const int K = 20;

int n, k;
int jump[N][K];
vector < int > e[N];
int tin[N];
int tout[N];
bool use[N];
int h[N];
int rev[N];
int tmr;

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

void dfs(int v, int hh) {
    use[v] = 1;
    tin[v] = tmr++;
    h[v] = hh;
    for (auto u: e[v])
        if (!use[u]) {
            dfs(u, hh + 1);
            jump[u][0] = v;
        }
    tout[v] = tmr;
}

bool isPar(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLCA(int v, int u) {
    if (isPar(v, u)) return v;
    if (isPar(u, v)) return u;
    for (int t = K - 1; t >= 0; t--) 
        if (!isPar(jump[v][t], u))
            v = jump[v][t];
    return jump[v][0];
}

void solve() {
    dfs(0, 0);
    jump[0][0] = 0;
    for (int i = 1; i < K; i++)
        for (int v = 0; v < n; v++)
            jump[v][i] = jump[jump[v][i - 1]][i - 1];

    int answer = 0;
    int cnt = 0;

    set < int > q;

    for (int i = 0; i < n; i++)
        rev[tin[i]] = i;

    int r = 0;
    int head = -1;
    for (int l = 0; l < n; l++) {
        if (l == r) {
            assert(q.empty());
            q.insert(tin[l]);
            cnt = 1;
            head = l;
            r++;
            //db2("empty", l);
        }
        for (;r < n;) {
            vector < int > nei;      
            auto it = q.lower_bound(tin[r]);
            if (it != q.end())
                nei.pb(*it);
            if (it != q.begin()) 
                nei.pb(*(--it)); 
            int bestLCA = -1;
            for (auto t: nei) {
                int o = getLCA(rev[t], r);
                if (bestLCA == -1 || h[o] > h[bestLCA]) {
                    bestLCA = o;
                }
            }
            //db(bestLCA + 1);
            int need;
            if (h[bestLCA] >= h[head]) {
                need = h[r] - h[bestLCA];
            }
            else {
                need = h[r] - h[bestLCA] + h[head] - h[bestLCA];
                
            }
            assert(need >= 0);

            if (cnt + need <= k) {
                q.insert(tin[r]);
                cnt += need;
                r++;
                if (h[bestLCA] < h[head])
                    head = bestLCA;
            }
            else
                break;
        }
        //db2(l, r);
        //if (r - l > 1) exit(0);
        //db2(l + 1, r);
        //db(cnt);
        //if (l == 1) exit(0);
        answer = max(answer, r - l);

        vector < int > nei;      
        q.erase(tin[l]);
        auto it = q.lower_bound(tin[l]);
        if (it != q.end())
            nei.pb(*it);
        if (it != q.begin()) 
            nei.pb(*(--it)); 
        int bestLCA = -1;
        for (auto t: nei) {
            int o = getLCA(rev[t], l);
            if (bestLCA == -1 || h[o] > h[bestLCA]) {
                bestLCA = o;
            }
        }
        assert(h[l] >= h[bestLCA]);
        cnt -= h[l] - h[bestLCA];
        //db(bestLCA + 1);
        //db2(h[l], h[bestLCA]);
        if (q.empty()) {
            cnt = 0;
            head = -1;
        }
        else {
            int v = *q.begin();
            int u = *q.rbegin();
            int o = getLCA(rev[v], rev[u]);
            if (h[o] > h[head]) {
                //db2(cnt, "here");
                cnt -= h[o] - h[head];
                head = o;
            }
        }
        //db(cnt);
        //if (l == 1) exit(0);
    }
    printf("%d\n", answer);
}

void stress() {

}


int main(){
#ifdef DEBUG
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