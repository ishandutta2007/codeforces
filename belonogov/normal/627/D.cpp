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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;

int a[N];
vector < int > e[N];
bool use[N];
int f[N];
int cnt[N];
int n, k;
bool can;

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
       scanf("%d", &a[i]); 
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

void dfs1(int v, int val) {
    use[v] = 1;
    cnt[v] = 1;
    int full = 0;
    int mx = 0;
    for (auto u: e[v]) {
        if (!use[u]) {
            dfs1(u, val);
            cnt[v] += cnt[u];
            if (cnt[u] == f[u])
                full += f[u];
            else
                mx = max(f[u], mx);
        }
    }
    if (a[v] < val) 
        f[v] = 0;
    else
        f[v] = full + 1 + mx;
}

void dfs2(int v, int val, int sz) {
    use[v] = 1;

    int full = 0;
    pair < int, int > mx1 = mp(0, -1);
    pair < int, int > mx2 = mp(0, -1);
    for (auto u: e[v]) 
        if (!use[u]) {
            if (cnt[u] == f[u])
                full += f[u];
            else {
                auto tmp = mp(f[u], u);
                if (mx2 < tmp) {
                    mx2 = tmp;
                    if (mx1 < mx2)
                        swap(mx1, mx2);
                }
            }
        }
    assert(sz <= n - cnt[v]);
    if (sz == n - cnt[v])
        full += sz;
    else {
        auto tmp = mp(sz, -1);
        if (mx2 < tmp) {
            mx2 = tmp;
            if (mx1 < mx2)
                swap(mx1, mx2);
        }
    }

    int sum = full + mx1.fr + 1;
    if (a[v] >= val) {
        can |= sum >= k; 
        //if (sum >= k) {
            //db2(sz, v + 1);
        //}
    }

    for (auto u: e[v])
        if (!use[u]) {
            int h = 0; 
            if (a[v] >= val) {
                if (cnt[u] == f[u]) {
                    h = sum - f[u];
                    assert(h >= 1);
                }
                else {
                    if (u == mx1.sc)
                        h = sum - mx1.fr + mx2.fr;
                    else
                        h = sum;
                }
            }
            dfs2(u, val, h);
        }
}


bool check(int val) {
    memset(use, 0, sizeof(use));
    dfs1(0, val);

    memset(use, 0, sizeof(use));
    can = 0;
    dfs2(0, val, 0);
    //for (int i = 0; i < n; i++)
        //db2(cnt[i], f[i]);

    return can;
}

void solve() {
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, a[i]); 

    //db(check(5));
    //return;
    int l = 0;
    int r = mx + 1;
    while (r - l > 1) {
        if (check((l + r) / 2))
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    }
    printf("%d\n", l);
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