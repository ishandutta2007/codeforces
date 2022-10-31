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

const int maxn = 1e5 + 5;
const int inf = 1e9;

vector<int> g[maxn];
int used[maxn];
int vis = 0;
void dfs(int v) {
    vis++;
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

map<pair<int,int>, ll> dist[maxn];

bool lucky(int x) {
    if (!x) {
        return false;
    }
    while (x) {
        int d = x % 10;
        if (d != 4 && d != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

ll get(int d, int p, int v) {
    if (!dist[d].count(mp(p, v))) {
        dist[d][mp(p, v)] = inf;
    }
    return dist[d][mp(p, v)];
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

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    map<int,int> cnt;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            vis = 0;
            dfs(i);
            cnt[vis]++;
        }
    }

    vector<pair<int,int>> a;
    for (auto kv : cnt) {
        a.pb(kv);
    }

    dist[0][mp(0, 0)] = 0;
    priority_queue<pair<ll, pair<int, pair<int,int>>>, vector<pair<ll, pair<int, pair<int,int>>>>, greater<pair<ll, pair<int, pair<int,int>>>>> q;
    q.push(mp(0, mp(0, mp(0, 0))));

    set<int> lk;
    for (int i = 1; i < maxn; i++) {
        if (lucky(i)) {
            lk.insert(i);
        }
    }


    while (!q.empty()) {
        int sum = q.top().snd.fst;
        int num = q.top().snd.snd.fst;
        int ptr = q.top().snd.snd.snd;
        int cd = q.top().fst;
        q.pop();

        if (cd != get(sum, num, ptr)) {
            continue;
        }

        if (lk.count(sum)) {
            cout << cd - 1 << endl;
            return 0;
        }

        if (num + 1 < a.size()) {
            if (get(sum, num + 1, 0) > cd) {
                dist[sum][mp(num + 1, 0)] = cd;
                q.push(mp(cd, mp(sum, mp(num + 1, 0))));
            }
        }

        if (ptr + 1 <= a[num].snd) {
            ll nd = cd + 1;
            ll ns = sum + a[num].fst;
            if (get(ns, num, ptr + 1) > cd) {
                dist[ns][mp(num, ptr + 1)] = nd;
                q.push(mp(nd, mp(ns, mp(num, ptr + 1))));
            }
        }
    }


    cout << -1 << endl;

    return 0;
}