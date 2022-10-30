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
#define ld double
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
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1005;
vector<int> g[maxn];
int a[maxn];
int cnt = 0;
int n, k;
bool can = false;
int deg[maxn];
vector<int> order;
int ans[maxn];
ll dist[maxn][maxn];

void rec(int p) {
    if (can) {
        return;
    }

    if (p == order.size()) {
        can = true;
        for (int i = 0; i < n; i++) {
            ans[i] = a[i];
        }
        return;
    }

    if (a[order[p]]) {
        rec(p + 1);
        return;
    }


    int ne = 0;
    int v = order[p];
    for (int to : g[v]) {
        ne += !a[to];
    }


    if (ne == 0) {
        rec(p + 1);
        return;
    }

    if (ne <= (k - cnt)) {
        vector<int> h;
        for (int to : g[v]) {
            if (!a[to]) {
                a[to] = 1;
                cnt++;
                h.pb(to);
            }
        }

        rec(p + 1);
        if (can) {
            return;
        }

        for (int x : h) {
            a[x] = 0;
            cnt--;
        }
    }

    if (ne != 1 && cnt + 1 <= k) {
        a[v] = 1;
        cnt++;
        rec(p + 1);
        if (can) {
            return;
        }
        cnt--;
        a[v] = 0;
    }
}

bool check(ll x) {
    order.clear();
    for (int i = 0; i < n; i++) {
        g[i].clear();
        a[i] = 0;
        deg[i] = 0;
    }
    cnt = 0;

    int e = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist[i][j] >= x) {
                //g[i].pb(j);
                //g[j].pb(i);
                //cout << i << " " << j << endl;
                deg[i]++;
                deg[j]++;
                e++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (deg[i]) {
            order.pb(i);
        }
    }


    sort(order.begin(), order.end(), [&](int u, int v) {
        return deg[u] > deg[v];
    });

    for (int i = 0; i < order.size(); i++) {
        for (int j = i + 1; j < order.size(); j++) {
            if (dist[order[i]][order[j]] >= x) {
                g[order[i]].pb(order[j]);
                g[order[j]].pb(order[i]);
            }
        }
    }


    int e2 = 0;
    for (int i = 0; i < min(k, (int)order.size()); i++) {
        e2 += deg[order[i]];
    }

    if (e2 < e) {
        return false;
    }



    can = false;
    rec(0);

    if (can) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!a[i] && !a[j]) {
                    assert(dist[i][j] < x);
                }
            }
        }
    }

    return can;
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

    scanf("%d %d", &n, &k);
    //n = 1000, k = 30;
    vector<pair<ll,ll>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        //x = rand() % 32000, y = rand() % 32000;
        //x = 1000 * cos(2 * pi / n * i);
        //y = 1000 * sin(2 * pi / n * i);
        a.pb(mp(x, y));
    }

    ll dd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dist[j][i] = dist[i][j] = sqr(a[i].fst - a[j].fst) + sqr(a[i].snd - a[j].snd);
            chmax(dd, dist[i][j]);
        }
    }


    ll lo = -1, hi = 40000LL * 40000LL * 2;
    while (hi - lo > 1) {
        ll mid = (lo + hi) >> 1;
        cerr << mid << endl;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    check(hi);
    cerr << dd << " " << hi << endl;

    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            b.pb(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!ans[i] && b.size() < k) {
            b.pb(i);
        }
    }

    assert(b.size() <= k);
    for (int i = 0; i < b.size(); i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", b[i] + 1);
    }
    cout << endl;

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}