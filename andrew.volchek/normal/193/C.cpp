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

//-----------------------------------------------------------------------------

const ld eps = 1e-9;
void g(vector<vector<ld>> a, vector<ld> b, vector<ll> &res) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && abs(a[j][i]) < eps) {
            j++;
        }

        if (j == n) {
            return;
        }

        swap(a[i], a[j]);
        swap(b[i], b[j]);

        for (int h = 0; h < n; h++) {
            if (h == i) {
                continue;
            }

            ld c = a[h][i] / a[i][i];
            for (int j = 0; j < n; j++) {
                a[h][j] -= a[i][j] * c;
            }

            b[h] -= c * b[i];
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = round(b[i] / a[i][i]);
    }
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


    map<vector<int>, vector<int>> s;
    for (int i = 0; i < (1 << 4); i++) {
        int x = i;
        vector<int> a;
        for (int j = 0; j < 4; j++) {
            a.pb(x & 1);
            x /= 2;
        }
        vector<int> h;
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                h.pb(abs(a[j] - a[k]));
                cnt += abs(a[j] - a[k]);
            }
        }
        if (cnt) {
            s[h] = a;
        }
    }

    vector<pair<vector<int>, vector<int>>> b;
    for (auto kv : s) {
        //cout << kv << endl;
        b.pb(mp(kv.fst, kv.snd));
    }

    vector<ll> a;
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }

    const int inf = 1e9;

    pair<ll,vector<ll>> bst(inf, vector<ll>());

    vector<vector<ld>> m(6, vector<ld>(6, 0));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            m[i][j] = b[j + 1].fst[i];
        }
    }

    for (int i = 0; i < 200005; i++) {
        bool good = true;
        vector<ld> d(6);
        for (int j = 0; j < 6; j++) {
            good &= (a[j] >= b[0].fst[j] * i);
            d[j] = a[j] - b[0].fst[j] * i;
        }

        vector<ll> res(6, 0);
        g(m, d, res);

        for (int j = 0; j < 6; j++) {
            ll c = 0;
            for (int h = 0; h < 6; h++) {
                c += b[h + 1].fst[j] * res[h];
            }
            good &= (c == (a[j] - b[0].fst[j] * i));
            good &= res[j] >= 0;
        }


        if (good) {
            vector<ll> g;
            g.pb(i);
            ll c = i;

            for (ll x : res) {
                g.pb(x);
                c += x;
            }

            chmin(bst, mp(c, g));
        }
    }

    if (bst.fst == inf) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> ans(4);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < bst.snd[i]; j++) {
            for (int h = 0; h < 4; h++) {
                ans[h].pb(b[i].snd[h]);
            }
        }
    }

    cout << ans[0].size() << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%c", ans[i][j] ? 'a' : 'b');
        }
        printf("\n");
    }


    return 0;
}