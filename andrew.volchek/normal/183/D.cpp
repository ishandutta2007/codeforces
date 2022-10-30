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


//-----------------------------------------------------------------------------

ld a[3005][305];
ld de[305][3005];
ld f[3005], nf[3005];
int used[3005], cu = 1;
ld dp[3005];

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
    //n = 3000, m = 300;

    for (int i = 0; i < n; i++) {
        ld s = 0.0;
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            //x = rand() % 1000;
            a[i][j] = x / 1000.0;
            s += a[i][j];
        }


        for (int j = 0; j < m; j++) {
            a[i][j] /= s;
        }

    }

    const int maxn = 3005;

    vector<int> ub(m, 0);

    for (int i = 0; i < m; i++) {
        fill(f, f + maxn, 0);
        f[0] = 1;
        cerr << i << endl;

        vector<int> st;
        st.pb(0);
        for (int j = 0; j < n; j++) {
            ld p = a[j][i];

            cu++;
            vector<int> nst;
            for (int x : st) {
                if (used[x] != cu) {
                    nst.pb(x);
                    used[x] = cu;
                }
                nf[x] += f[x] * (1 - p);
                if (used[x + 1] != cu) {
                    nst.pb(x + 1);
                    used[x + 1] = cu;
                }
                nf[x + 1] += f[x] * p;
                de[i][x + 1] += f[x] * p;
            }

            for (int x : st) {
                f[x] = 0;
            }

            st.clear();
            for (int y : nst) {
                if (nf[y] > 1e-20) {
                    f[y] = nf[y];
                    st.pb(y);
                }
                nf[y] = 0;
            }
        }

        for (int j = 1; j < maxn; j++) {
            if (de[i][j] > 1e-20) {
                ub[i] = j;
            }
            de[i][j] += de[i][j - 1];
        }
    }

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;


    const ld inf = 1e18;
    fill(dp, dp + maxn, -inf);
    dp[0] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = maxn - 1; j >= 0; j--) {
            for (int k = 0; k <= ub[i]; k++) {
                chmax(dp[j + k], dp[j] + de[i][k]);
            }
        }
    }

    ld res = -inf;
    for (int i = 0; i <= n; i++) {
        chmax(res, dp[n]);
    }


    cout.precision(10);
    cout << fixed << res << endl;

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;



    return 0;
}