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


const int maxn = 5005;
const ll inf = 1e18;

ll a[maxn], b[maxn], c[maxn], d[maxn], x[maxn];
ll f[maxn][20];
int used[maxn][maxn];
int cu = 1;
ll nf[maxn][20];

ll get(int u, int v) {
    return f[u][10 + u - v];
}

#define set _set

void set(int u, int v, ll val) {
    f[u][10 + u - v] = val;
}

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif


    int n, s, e;
    scanf("%d %d %d", &n, &s, &e);

    for (int i = 1; i <= n; i++) {
        int y;
        scanf("%d", &y);
        x[i] = y;
    }

    for (int i = 1; i <= n; i++) {
        int y;
        scanf("%d", &y);
        a[i] = y + x[i];
    }

    for (int i = 1; i <= n; i++) {
        int y;
        scanf("%d", &y);
        b[i] = y - x[i];
    }

    for (int i = 1; i <= n; i++) {
        int y;
        scanf("%d", &y);
        c[i] = y + x[i];
    }

    for (int i = 1; i <= n; i++) {
        int y;
        scanf("%d", &y);
        d[i] = y - x[i];
    }

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < 20; j++) {
            f[i][j] = inf;
            nf[i][j] = inf;
        }
    }

    vector<pair<int,int>> st;
    st.pb(mp(0, 0));
    set(0, 0, 0);



    for (int i = 1; i <= n; i++) {
        cu++;

        vector<pair<int,int>> nst;

        auto relax = [&](int u, int v, ll val) {
            chmin(nf[u][10 + u - v], val);
            if (used[u][v] != cu) {
                used[u][v] = cu;
                nst.pb(mp(u, v));
            }
        };

        for (auto p : st) {
            int toLeft = p.fst;
            int toRight = p.snd;

            ll val = get(toLeft, toRight);

            if (i == s) {
                if (toLeft && i > 1) {
                    relax(toLeft - 1, toRight, val + c[i]);
                }

                if (i < n) {
                    relax(toLeft, toRight + 1, val + d[i]);
                }
            } else if (i == e) {
                if (toRight && i > 1) {
                    relax(toLeft, toRight - 1, val + a[i]);
                }

                if (i < n) {
                    relax(toLeft + 1, toRight, val + b[i]);
                }
            } else {
                if (toRight) {
                    relax(toLeft, toRight, val + d[i] + a[i]);
                }

                if (toLeft) {
                    relax(toLeft, toRight, val + c[i] + b[i]);
                }

                if (toLeft && toRight) {
                    relax(toLeft - 1, toRight - 1, val + a[i] + c[i]);
                }

                relax(toLeft + 1, toRight + 1, val + d[i] + b[i]);
            }
        }

        for (auto p : st) {
            set(p.fst, p.snd, 0);
        }

        st.clear();

        for (auto p : nst) {

            if (i == n || !(p.fst == 0 && p.snd == 0)) {

                f[p.fst][p.fst - p.snd + 10] = nf[p.fst][p.fst - p.snd + 10];
                st.pb(p);
            }
            nf[p.fst][p.fst - p.snd + 10] = inf;
        }


    }

    cout << get(0, 0) << endl;



    return 0;
}