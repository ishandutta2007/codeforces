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
#include <future>

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

const ld pi = acos(-1.0);

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


//--------------------------------------------------------------------------

const int maxn = 2e5 + 5;
const int inf = 1e9;

struct node {
    node *l, *r;
    int val;
    node() {
        l = r = nullptr;
        val = inf;
    }
};

int ptr = 0;
node pool[maxn * 60];

node* get() {
    assert(ptr < maxn * 60);
    return pool + ptr++;
}

node* build(int l, int r) {
    if (l == r) {
        node* v = get();
        return v;
    }
    int c = (l + r) >> 1;
    node* v = get();
    v->l = build(l, c);
    v->r = build(c + 1, r);
    return v;
}

node* modify(node* v, int l, int r, int i, int val) {
    if (l == r) {
        node* nw = get();
        *nw = *v;
        chmin(nw->val, val);
        return nw;
    }
    int c = (l + r) >> 1;
    node* nw = get();
    *nw = *v;
    if (i <= c) {
        nw->l = modify(v->l, l, c, i, val);
    } else {
        nw->r = modify(v->r, c + 1, r, i, val);
    }

    nw->val = min(nw->l->val, nw->r->val);
    return nw;
}

int get(node* v, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return v->val;
    }
    int res = inf;
    int c = (l + r) >> 1;
    if (i <= c) {
        chmin(res, get(v->l, l, c, i, j));
    }
    if (c < j) {
        chmin(res, get(v->r, c + 1, r, i, j));
    }

    return res;
}

struct tree {
    int tr[maxn * 4];
    tree() {
        fill(tr, tr + maxn * 4, inf);
    }
    void modify(int v, int l, int r, int i, int val) {
        if (l == r) {
            chmin(tr[v], val);
            return;
        }
        int c = (l + r) >> 1;
        if (i <= c) {
            modify(2 * v, l, c, i, val);
        } else {
            modify(2 * v + 1, c + 1, r, i, val);
        }

        tr[v] = min(tr[2 * v], tr[2 * v + 1]);
    }

    int get(int v, int l, int r, int i, int j) {
        if (i <= l && r <= j) {
            return tr[v];
        }
        int res = inf;
        int c = (l + r) >> 1;
        if (i <= c) {
            chmin(res, get(2 * v, l, c, i, j));
        }
        if (c < j) {
            chmin(res, get(2 * v + 1, c + 1, r, i, j));
        }
        return res;
    }
};


vector<int> solve(vector<int> a, vector<pair<int,int>> q) {
    int n = a.size();
    vector<vector<pair<int,int>>> q2(n);
    for (int i = 0; i < q.size(); i++) {
        q2[q[i].fst].pb(mp(q[i].snd, i));
    }
    vector<int> ans(q.size(), inf);
    tree tr, trN;



    vector<int> cc = a;
    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    for (int& x : a) {
        x = lower_bound(cc.begin(), cc.end(), x) - cc.begin();
    }




    for (int i = n - 1; i >= 0; i--) {
        int nxt = trN.get(1, 0, n, a[i], n);
        if (nxt == inf) {
            for (auto p : q2[i]) {
                ans[p.snd] = tr.get(1, 0, n - 1, 0, p.fst);
            }
            trN.modify(1, 0, n, a[i], i);
            continue;
        }

        int lo = a[i], hi = a[nxt];
        int diff = cc[hi] - cc[lo];

        int iter = 0;
        while (true) {
            iter++;
            tr.modify(1, 0, n - 1, nxt, diff);
            if (diff == 0) {
                break;
            }
            if (nxt + 1 >= n) {
                break;
            }
            assert(lo <= hi);
            nxt = trN.get(1, 0, n, lo, hi);
            if (nxt == inf) {
                break;
            }
            assert(0 <= hi && hi < cc.size());
            assert(0 <= a[nxt] && a[nxt] < cc.size());
            assert(a[nxt] <= hi);
            //assert(cc[a[nxt]] <= cc[hi]);

            //assert(diff >= cc[a[nxt]] - cc[a[i]]);
            diff = cc[a[nxt]] - cc[a[i]];

            int need = diff / 2;
            //assert(diff == 0 || cc[hi] - cc[lo] > need);

            int l = a[i] - 1, r = cc.size();
            while (r - l > 1) {
                int mid = (l + r) >> 1;
                if (cc[mid] - cc[a[i]] > need) {
                    r = mid;
                } else {
                    l = mid;
                }
            }

            //assert(hi > l || diff == 0);
            hi = l;
            //assert(iter < 30);
        }
        //cerr << iter << endl;

        for (auto p : q2[i]) {
            ans[p.snd] = tr.get(1, 0, n - 1, 0, p.fst);
        }
        trN.modify(1, 0, n, a[i], i);
    }

    return ans;
}


int main() {
    srand(134);

retry:
#ifdef LOCAL
    //gen();
    //return 0;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif


    int n;
    scanf("%d", &n);
    //n = 1e5;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
       // a[i] = rand();
    }
    int m;
    scanf("%d", &m);
    //m = 3e5;
    vector<pair<int,int>> q(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &q[i].fst, &q[i].snd);
        q[i].fst--;
        q[i].snd--;

    }
    vector<int> ans(m, inf);
    for (int i = 0; i < 2; i++) {
        for (int& x : a) {
            x = -x;
        }
        auto res = solve(a, q);
        for (int j = 0; j < m; j++) {
            chmin(ans[j], res[j]);
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}