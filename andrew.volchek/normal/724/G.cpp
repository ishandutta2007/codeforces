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
#include <limits>
#include <tuple>
#include <complex>
#include <numeric>

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

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
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

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 2e5 + 5;
ll cost[maxn];
vector<pair<int, int>> g[maxn];
ll mark[maxn];
int inT[maxn];
int used[maxn];
int d[maxn];
int cu = 1;



const ll mod = 1000000007;

int pathCnt[100005][64][2];
int dp[100005][64][2];


void add(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

void dfs(int v, int p) {


    for (int i = 0; i < 63; i++) {
        dp[v][i][0] = 1;
        //tmp[v][i][0] = 1;
    }

    used[v] = cu;
    for (auto to : g[v]) {
        if (!used[to.fst]) {
            mark[to.fst] = mark[v] ^ cost[to.snd];
            inT[to.snd] = 1;
            d[to.fst] = d[v] + 1;
            dfs(to.fst, v);


            for (int i = 0; i < 63; i++) {
                ll x = dp[to.fst][i][0], y = dp[to.fst][i][1];
                if (cost[to.snd] & (1LL << i)) {
                    swap(x, y);
                }
                add(pathCnt[cu][i][0], x * dp[v][i][0] % mod);
                add(pathCnt[cu][i][0], y * dp[v][i][1] % mod);
                add(pathCnt[cu][i][1], y * dp[v][i][0] % mod);
                add(pathCnt[cu][i][1], x * dp[v][i][1] % mod);

                add(dp[v][i][0], x);
                add(dp[v][i][1], y);
            }
        }
    }
}

int uu[maxn], vv[maxn];


vector<pair<ll, ll>> get(vector<ll> a) {
    ll res = 0;
    vector<int> used(a.size());

    for (int i = 62; i >= 0; i--) {
        int id = -1;
        for (int j = 0; j < a.size(); j++) {
            if (used[j]) {
                continue;
            }

            if (a[j] & (1LL << i)) {
                id = j;
            }
        }

        if (id != -1) {
            res++;
            used[id] = 1;
            ll x = a[id];
            for (int j = 0; j < a.size(); j++) {
                if (j != id && (a[j] & (1LL << i))) {
                    a[j] ^= x;
                }
            }
        }
    }

    vector<pair<ll, ll>> ans(63, mp(1, 0));



    for (int i = 0; i < a.size(); i++) {
        if (used[i]) {
            for (int j = 0; j < 63; j++) {
                if (a[i] & (1LL << j)) {
                    ans[j] = mp((ans[j].fst + ans[j].snd) % mod, (ans[j].fst + ans[j].snd) % mod);
                } else {
                    ans[j] = mp(ans[j].fst * 2 % mod, ans[j].snd * 2 % mod);
                }
            }
        }
    }
    return ans;
}

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif


    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        cost[i] = w;
        uu[i] = u, vv[i] = v;
        g[u].pb(mp(v, i));
        g[v].pb(mp(u, i));
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, i);
            cu++;
        }
    }

    vector<vector<ll>> f(cu - 1);


    for (int i = 0; i < m; i++) {
        if (!inT[i]) {
            int c = used[uu[i]];
            ll val = mark[uu[i]] ^ mark[vv[i]] ^ cost[i];
            f[c - 1].pb(val);
        }
    }

    ll ans = 0;



    for (int i = 0; i < cu - 1; i++) {
        auto val = get(f[i]);
        //cout << val << endl;
       // cout << val << endl;
        for (int j = 0; j < 63; j++) {
            ans += (pathCnt[i + 1][j][0] * 1LL * val[j].snd % mod) * ((1LL << j) % mod) % mod;
            ans += (pathCnt[i + 1][j][1] * 1LL * val[j].fst % mod) * ((1LL << j) % mod) % mod;
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}