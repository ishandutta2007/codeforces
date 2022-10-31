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
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
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
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
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
const ll inf = 1e9;

ll dp[maxn][2];

vector<int> g[maxn];
vector<int> childs[maxn];
vector<int> order;

void dfs(int v, int p = -1) {
    for (int to : g[v]) {
        if (to != p) {
            childs[v].pb(to);
            dfs(to, v);
        }
    }
    order.pb(v);
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    ll n, x, y;
    cin >> n >> x >> y;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);

    for (int v : order) {
        if (childs[v].empty()) {
            dp[v][0] = inf;
            dp[v][1] = 1;
        } else {
            int sum = 0;
            vector<int> s;
            for (int to : childs[v]) {
                sum += min(dp[to][0], dp[to][1]);
                s.pb(-min(dp[to][0], dp[to][1]) + dp[to][1]);
            }
            dp[v][1] = sum + 1;
            for (int to : childs[v]) {
                chmin(dp[v][1], sum - min(dp[to][0], dp[to][1]) + dp[to][1]);
            }

            dp[v][0] = inf;

            if (s.size() > 1) {
                sort(s.begin(), s.end());
                dp[v][0] = sum + s[0] + s[1] - 1;
            }
        }
    }


    if (x < y) {
        ll s = min(dp[1][0], dp[1][1]);
        //cout << s << endl;
        cout << (s - 1) * y + (n - 1 - (s - 1)) * x << endl;
    } else {
        if (n == 2) {
            cout << x << endl;
        } else {
            bool was = false;
            for (int i = 1; i <= n; i++) {
                was |= g[i].size() == n - 1;
            }
            if (was) {
                cout << (n - 2) * y + x << endl;
            } else {
                cout << (n - 1) * y << endl;
            }
        }
    }


    return 0;
}