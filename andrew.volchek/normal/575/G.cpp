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
const int inf = 1e9;

vector<pair<int,int>> g[maxn];
int distZ[maxn], prZ[maxn];
int dist[maxn];
pair<int,int> pr[maxn];



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
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }

    fill(distZ, distZ + maxn, inf);

    queue<int> q;
    distZ[n - 1] = 0;
    q.push(n - 1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : g[v]) {
            if (to.snd) {
                continue;
            }
            if (distZ[to.fst] == inf) {
                distZ[to.fst] = distZ[v] + 1;
                prZ[to.fst] = v;
                q.push(to.fst);
            }
        }
    }

    fill(dist, dist + maxn, inf);
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : g[v]) {
            if (dist[to.fst] == inf) {
                dist[to.fst] = dist[v] + 1;
                q.push(to.fst);
            }
        }
    }

    fill(pr, pr + maxn, mp(inf, -1));

    pair<int, vector<pair<int,int>>> bst;
    bst.fst = inf;

    for (int i = 0; i < n; i++) {
        if (distZ[i] != inf) {
            if (dist[i] < bst.fst) {
                bst.fst = dist[i];
                bst.snd = {mp(distZ[i], i)};
            } else if (dist[i] == bst.fst) {
                bst.snd.pb(mp(distZ[i], i));
            }
        }
    }



    if (bst.fst == 0) {
        printf("0\n");
        printf("%d\n", distZ[0] + 1);
        int v = 0;
        bool f = false;
        while (true) {
            if (f) {
                printf(" ");
            }
            f = true;
            printf("%d", v);
            if (v == n - 1) {
                break;
            }
            v = prZ[v];
        }
    } else {
        vector<pair<int,int>> c = bst.snd;

        vector<int> ans;
        while (true) {
            if (pr[0].snd != -1) {
                break;
            }

            int mi = 10;
            for (auto p : c) {
                for (auto to : g[p.snd]) {
                    if (dist[to.fst] + 1 == dist[p.snd]) {
                        mi = min(mi, to.snd);
                    }
                }
            }

            ans.pb(mi);

            set<int> was;
            for (auto p : c) {
                for (auto to : g[p.snd]) {
                    if (dist[to.fst] + 1 == dist[p.snd] && to.snd == mi) {
                        was.insert(to.fst);
                        chmin(pr[to.fst], mp(p.fst, p.snd));
                    }
                }
            }

            c.clear();
            for (int x : was) {
                c.pb(mp(pr[x].fst, x));
            }
        }

        for (int x : ans) {
            printf("%d", x);
        }

        printf("\n");


        vector<int> pa;

        int v = 0;
        for (int i = 0; i < bst.fst; i++) {
            pa.pb(v);
            v = pr[v].snd;
        }

        while (true) {
            pa.pb(v);
            if (v == n - 1) {
                break;
            }
            v = prZ[v];
        }

        printf("%d\n", pa.size());
        for (int i = 0; i < pa.size(); i++) {
            if (i) {
                printf(" ");
            }
            printf("%d", pa[i]);
        }
    }




    return 0;
}