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

const int maxn = 1e6 + 5;

pair<int,int> tr[4 * maxn];

pair<int,int> get(int v, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return tr[v];
    }
    pair<int,int> res(0, 0);
    int c = (l + r) >> 1;
    if (i <= c) {
        chmax(res, get(2 * v, l, c, i, j));
    }
    if (c < j) {
        chmax(res, get(2 * v + 1, c + 1, r, i, j));
    }
    return res;
}

void modify(int v, int l, int r, int i, pair<int,int> val) {
    if (l == r) {
        chmax(tr[v], val);
        return;
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        modify(2 * v, l, c, i, val);
    } else {
        modify(2 * v + 1, c + 1, r, i, val);
    }

    tr[v] = max(tr[2 * v], tr[2 * v + 1]);
}


int a[maxn];
vector<pair<int, int>> q[maxn];
int ans[maxn];


pair<int, int> l_res[maxn], r_res[maxn];



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

    vector<int> cc;

    int n, m;
    scanf("%d %d", &n, &m);
    //n = 4e5;
   // m = n;

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        //a[i] = rand() % 1000000000;
        cc.pb(a[i]);
    }

    for (int i = 0; i < m; i++) {
        int id, v;
        scanf("%d %d", &id, &v);
        //id = i + 1, v = i + 1;
        cc.pb(v);
        q[id].pb(mp(v, i));
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(cc.begin(), cc.end(), a[i]) - cc.begin();

        for (auto &x : q[i]) {
            x.fst = lower_bound(cc.begin(), cc.end(), x.fst) - cc.begin();
        }
    }

    int gans = 0;

    fill(tr, tr + 4 * maxn, mp(0, 0));

    fill(ans, ans + m, 1);

    for (int i = 1; i <= n; i++) {
        for (auto x : q[i]) {
            if (0 <= x.fst - 1) {
                ans[x.snd] += get(1, 0, cc.size(), 0, x.fst - 1).fst;
            }
        }

        auto res = (0 <= a[i] - 1) ? get(1, 0, cc.size(), 0, a[i] - 1) : mp(0, 0);
        l_res[i] = res;
        modify(1, 0, cc.size(), a[i], mp(res.fst + 1, -i));
    }

    gans = get(1, 0, cc.size(), 0, cc.size()).fst;

    fill(tr, tr + 4 * maxn, mp(0, n + 1));

    for (int i = n; i >= 1; i--) {
        for (auto x : q[i]) {
            if (x.fst + 1 <= cc.size()) {
                ans[x.snd] += get(1, 0, cc.size(), x.fst + 1, cc.size()).fst;
            }
        }

        auto res = (a[i] + 1 <= cc.size()) ? get(1, 0, cc.size(), a[i] + 1, cc.size()) : mp(0, n + 1);
        r_res[i] = res;
        modify(1, 0, cc.size(), a[i], mp(res.fst + 1, i));
    }

    map<pair<int,int>, int> was;
    for (int i = 1; i <= n; i++) {
        was[mp(l_res[i].fst, r_res[i].fst)]++;
    }


    for (int i = 1; i <= n; i++) {
        bool can = false;
        if (1 + l_res[i].fst + r_res[i].fst == gans) {
            can |= was[mp(l_res[i].fst, r_res[i].fst)] > 1;
        } else {
            can = true;
        }

        if (can) {
            for (auto x : q[i]) {
                chmax(ans[x.snd], gans);
            }
        } else {
            for (auto x : q[i]) {
                chmax(ans[x.snd], gans - 1);
            }
        }
    }


    //cout << gans << endl;


    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
        //assert(abs(ans[i] - gans) <= 1);
    }



    return 0;
}