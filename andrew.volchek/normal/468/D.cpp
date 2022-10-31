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
ostream& operator << (ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream& operator << (ostream &s, const vector<U> &x) {
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

//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;
const int inf = 1e9;

vector<pair<int, int>> g[maxn];
pair<int, vector<int>> bst(1e9, {});
int n;
ll cost = 0;

int dfs(int v, int p = -1) {
    int sz = 1;
    for (auto to : g[v]) {
        if (to.fst == p) {
            continue;
        }

        int c = dfs(to.fst, v);
        sz += c;
        cost += to.snd * 2LL * min(c, n - c);
        
        chmin(bst, mp(abs(c - (n - c)), vector<int>({c > n - c ? to.fst : v})));
    }

    return sz;
}

vector<int> comp;
void dfs2(int v, int pr) {
    comp.pb(v);
    for (auto to : g[v]) {
        if (to.fst != pr) {
            dfs2(to.fst, v);
        }
    }
}

pair<int,int> t[maxn * 4];

void modify(int v, int l, int r, int i, int val) {
    if (l == r) {
        t[v] = mp(val, l);
        return;
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        modify(2 * v, l, c, i, val);
    } else {
        modify(2 * v + 1, c + 1, r, i, val);
    }

    t[v] = min(t[2 * v], t[2 * v + 1]);
}

pair<int,int> get(int v, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return t[v];
    }

    pair<int,int> res(inf, 0);
    int c = (l + r) >> 1;

    if (i <= c) {
        chmin(res, get(2 * v, l, c, i, j));
    }

    if (c < j) {
        chmin(res, get(2 * v + 1, c + 1, r, i, j));
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

    scanf("%d", &n);
    //n = 100000;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;

        u = i + 2;
        v = rand() % (i + 1) + 1;
        w = 1;
        scanf("%d %d %d", &u, &v, &w);
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }

    if (n == 1) {
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }

    dfs(1);



    fill(t, t + maxn * 4, mp(inf, 0));

    vector<int> ci(n + 1, -1);
    vector<int> cl, cr;
    vector<int> cs;
    int sz = 0;
    int cz = 1;

    set<pair<int, int>> s;


    if (bst.snd.size() == 2) {
        for (int i = 0; i < 2; i++) {
            comp.clear();
            dfs2(bst.snd[i], bst.snd[1 - i]);
            cl.pb(cz), cr.pb(cz + comp.size() - 1);
            cs.pb(comp.size() * 2);
            for (int x : comp) {
                ci[x] = sz;
                modify(1, 0, maxn - 1, cz++, x);
            }
            s.insert(mp(comp.size() * 2, sz));
            sz++;
        }
    } else {
        for (auto to : g[bst.snd[0]]) {
            comp.clear();
            dfs2(to.fst, bst.snd[0]);
            cl.pb(cz), cr.pb(cz + comp.size() - 1);
            cs.pb(comp.size() * 2);
            for (int x : comp) {
                ci[x] = sz;
                modify(1, 0, maxn - 1, cz++, x);
            }
            s.insert(mp(comp.size() * 2, sz));
            sz++;
        }
        modify(1, 0, maxn - 1, cz++, bst.snd[0]);
        //cs.pb(1);
        //s.insert(mp(1, sz));
    }





    vector<int> ans(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int big = s.empty() ? 0 : s.rbegin()->fst;
        int bigI = s.empty() ? -1 : s.rbegin()->snd;
        if (ci[i] == bigI || big <= n - i) {
            if (ci[i] == -1) {
                auto r = get(1, 0, maxn - 1, 0, maxn - 1);
                assert(r.fst != inf);
                ans[i] = r.fst;
                modify(1, 0, maxn - 1, r.snd, inf);
                if (ci[r.fst] != -1) {
                    s.erase(mp(cs[ci[r.fst]], ci[r.fst]));
                    cs[ci[r.fst]]--;
                    s.insert(mp(cs[ci[r.fst]], ci[r.fst]));
                }
            } else {
                pair<int, int> r(inf, 0);

                if (0 <= cl[ci[i]] - 1) {
                    chmin(r, get(1, 0, maxn - 1, 0, cl[ci[i]] - 1));
                }

                chmin(r, get(1, 0, maxn - 1, cr[ci[i]] + 1, maxn - 1));
                assert(r.fst != inf);
                ans[i] = r.fst;
                modify(1, 0, maxn - 1, r.snd, inf);

                if (ci[i] != -1) {
                    s.erase(mp(cs[ci[i]], ci[i]));
                    cs[ci[i]]--;
                    s.insert(mp(cs[ci[i]], ci[i]));
                }

                if (ci[r.fst] != -1) {
                    s.erase(mp(cs[ci[r.fst]], ci[r.fst]));
                    cs[ci[r.fst]]--;
                    s.insert(mp(cs[ci[r.fst]], ci[r.fst]));
                }
            }
        } else {
            auto r = get(1, 0, maxn - 1, cl[bigI], cr[bigI]);
            assert(r.fst != inf);
            ans[i] = r.fst;
            modify(1, 0, maxn - 1, r.snd, inf);

            if (ci[i] != -1) {
                s.erase(mp(cs[ci[i]], ci[i]));
                cs[ci[i]]--;
                s.insert(mp(cs[ci[i]], ci[i]));
            }

            if (ci[r.fst] != -1) {
                s.erase(mp(cs[ci[r.fst]], ci[r.fst]));
                cs[ci[r.fst]]--;
                s.insert(mp(cs[ci[r.fst]], ci[r.fst]));
            }
        }
    }

    cout << cost << endl;
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }

    return 0;
}