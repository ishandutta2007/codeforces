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

    int n, k;
    cin >> n >> k;
    ll b;
    cin >> b;
    vector<pair<ll, int>> a;
    vector<ll> c;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        c.pb(x);
        if (i != n - 1) {
            a.pb(mp(x, i + 1));
        }
    }

    vector<int> used(n + 1, 0);

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll s = 0;
    for (int i = 0; i < k; i++) {
        used[a[i].snd] = 1;
        s += a[i].fst;
    }

    int ans = n;

    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            if (s > b) {
                chmin(ans, i);
            }
        } else {
            ll x = s - a[k - 1].fst + c[i - 1];
            if (x > b) {
                chmin(ans, i);
            }
        }
    }

    cout << ans << endl;



    return 0;
}