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

const int maxn = 1005;

ll a[maxn][maxn];

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    ll sx = 0, sy = 0;
    ll cs = 0;

    ll sx2 = 0, sy2 = 0;

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);

            sx += (i * 4 + 2) * 1LL * x;
            sy += (j * 4 + 2) * 1LL * x;
            cs += x;

            sx2 += (i * 4 + 2) * 1LL * (i * 4 + 2) * x;
            sy2 += (j * 4 + 2) * 1LL * (j * 4 + 2) * x;
        }
    }

    pair<ll, ll> bstX(1e18, -1);
    for (ll i = 0; i <= n; i++) {
        ll f = sqr(i * 4) * cs - 2LL * (i * 4) * sx + sx2;
        bstX = min(bstX, mp(f, i));
    }

    pair<ll, ll> bstY(1e18, -1);
    for (ll i = 0; i <= m; i++) {
        ll f = sqr(i * 4) * cs - 2LL * (i * 4) * sy + sy2;
        bstY = min(bstY, mp(f, i));
    }

    cout << bstX.fst + bstY.fst << endl;
    cout << bstX.snd << " " << bstY.snd << endl;



    return 0;
}