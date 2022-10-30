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
const int inf = 1e9 + 5;

set<pair<int,int>> tr[4 * maxn];

void add(int v, int l, int r, int i, pair<int,int> val) {
    tr[v].insert(val);
    if (l == r) {
        return;
    }

    int c = (l + r) >> 1;
    if (i <= c) {
        add(2 * v, l, c, i, val);
    } else {
        add(2 * v + 1, c + 1, r, i, val);
    }
}

void del(int v, int l, int r, int i, pair<int,int> val) {
    tr[v].erase(val);
    if (l == r) {
        return;
    }

    int c = (l + r) >> 1;
    if (i <= c) {
        del(2 * v, l, c, i, val);
    } else {
        del(2 * v + 1, c + 1, r, i, val);
    }
}

pair<int,int> get(int v, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return tr[v].empty() ? mp(inf, -1) : *tr[v].begin();
    }

    int c = (l + r) >> 1;
    pair<int,int> res(inf, -1);

    if (i <= c) {
        chmin(res, get(2 * v, l, c, i, j));
    }

    if (c < j) {
        chmin(res, get(2 * v + 1, c + 1, r, i, j));
    }

    return res;
};


int a[maxn], b[maxn], c[maxn], d[maxn];
int pr[maxn];

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

    int n;
    scanf("%d", &n);

    vector<int> cc;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
        cc.pb(a[i]);
        cc.pb(c[i]);
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(cc.begin(), cc.end(), a[i]) - cc.begin();
        c[i] = lower_bound(cc.begin(), cc.end(), c[i]) - cc.begin();
    }

    for (int i = 0; i < n; i++) {
        add(1, 0, maxn - 1, a[i], mp(b[i], i));
    }

    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push(mp(mp(0, 0), mp(0, -1)));

    while (!q.empty()) {
        int x = q.front().fst.fst;
        int y = q.front().fst.snd;
        int dist = q.front().snd.fst;
        int v = q.front().snd.snd;
        q.pop();

        while (true) {
            auto r = get(1, 0, maxn - 1, 0, x);
            if (r.snd == -1 || r.fst > y) {
                break;
            }

            if (r.snd == n - 1) {
                vector<int> ans;
                int u = v;
                while (u != -1) {
                    ans.pb(u);
                    u = pr[u];
                }
                reverse(ans.begin(), ans.end());
                ans.pb(n - 1);
                cout << ans.size() << endl;
                for (int x : ans) {
                    printf("%d ", x + 1);
                }
                return 0;
            }

            del(1, 0, maxn - 1, a[r.snd], r);
            pr[r.snd] = v;
            q.push(mp(mp(c[r.snd], d[r.snd]), mp(dist + 1, r.snd)));
        }
    }

    cout << -1 << endl;

    return 0;
}