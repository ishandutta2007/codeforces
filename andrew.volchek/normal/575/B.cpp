#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair <U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;
const ll mod = 1000000007;

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}



int dp[maxn][2];
vector<pair<int,int>> g[maxn];

ll ans = 0;

pair<int,int> dfs(int v, int pr) {
    pair<int,int> res(dp[v][0], dp[v][1]);

    for (auto to : g[v]) {
        if (to.fst == pr) {
            continue;
        }

        auto r = dfs(to.fst, v);

        if (to.snd == 1) {
            int k = r.fst;
            if (k) {
                ans += ((1 + mod - bpow(2, k)) * bpow(1 + mod - 2, mod - 2) % mod);
                ans %= mod;
            }
        } else if (to.snd == -1) {
            int k = r.snd;
            if (k) {
                ans += ((1 + mod - bpow(2, k)) * bpow(1 + mod - 2, mod - 2) % mod);
                ans %= mod;
            }
        }

        res.fst += r.fst;
        res.snd += r.snd;
    }

    return res;
}

int d[maxn], p[20][maxn];

void dfs2(int v, int pr) {
    p[0][v] = pr;
    for (int i = 1; i < 20; i++) {
        p[i][v] = p[i - 1][p[i - 1][v]];
    }

    for (auto to : g[v]) {
        if (to.fst == pr) {
            continue;
        }
        d[to.fst] = d[v] + 1;
        dfs2(to.fst, v);
    }
}

int lca(int a, int b) {
    if (d[a] < d[b]) {
        swap(a, b);
    }

    int diff = d[a] - d[b];
    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) {
            a = p[i][a];
        }
    }

    if (a == b) {
        return a;
    }

    int res;
    for (int i = 19; i >= 0; i--) {
        if (p[i][a] == p[i][b]) {
            res = p[i][a];
        } else {
            a = p[i][a];
            b = p[i][b];
        }
    }

    return res;
}

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        g[u].pb(mp(v, w));
        g[v].pb(mp(u, -w));
    }

    dfs2(1, 1);

    int k;
    scanf("%d", &k);

    vector<int> a;
    a.pb(1);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        a.pb(x);
    }

    for (int i = 0; i + 1 < k + 1; i++) {
        int u = a[i], v = a[i + 1];

        int w = lca(u, v);

        dp[u][0]++;
        dp[w][0]--;
        dp[v][1]++;
        dp[w][1]--;
    }

    dfs(1, 1);

    cout << ans << endl;

    return 0;
}