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


//-----------------------------------------------------------------------------

const int maxn = 3005;
ll f[maxn][maxn];
const ll inf = 1e18;

vector<int> cc;

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();
        freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cc.pb(a[i] - i);
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            f[i][j] = inf;
        }
    }

    for (int i = 1; i <= n; i++) {
        int id = lower_bound(cc.begin(), cc.end(), a[i] - i) - cc.begin();


        ll res = inf;
        ll c = 0;
        for (int j = i; j >= 1; j--) {
            c += abs(a[j] - (a[i] - (i - j)));
            chmin(res, c + f[j - 1][id]);
        }


        c = 0;
        for (int j = i; j <= n; j++) {
            c += abs(a[j] - (a[i] + (j - i)));
            chmin(f[j][id], res + c);
        }

        for (int j = 1; j < cc.size(); j++) {
            chmin(f[i][j], f[i][j - 1]);
        }
    }



    ll ans = inf;
    for (int i = 0; i < cc.size(); i++) {
        chmin(ans, f[n][i]);
    }

    cout << ans << endl;



    return 0;
}