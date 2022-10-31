#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <queue>
#include <assert.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define y1 _y1

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

ll a1, h1;
ll x1, y1;
ll a2, h2;
ll x2, y2;
ll m;

ll f1(ll x) {
    return (x * x1 + y1) % m;
}

ll f2(ll x) {
    return (x * x2 + y2) % m;
}

int main() {
    //freopen("a.in", "r", stdin);

    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;

    const int magic = 2e6;
    ll ans = 0;

    for (int i = 0; i < magic; i++) {
        if (h1 == a1 && h2 == a2) {
            cout << ans << endl;
            return 0;
        }

        h1 = f1(h1);
        h2 = f2(h2);
        ans++;
    }

    ll id1 = -1, len1 = 0, id2 = -1, len2 = 0;

    ll s1 = h1;
    do {
        s1 = f1(s1);

        if (s1 == a1) {
            id1 = len1;
        }

        len1++;
    } while (s1 != h1);

    ll s2 = h2;
    do {
        s2 = f2(s2);

        if (s2 == a2) {
            id2 = len2;
        }

        len2++;
    } while (s2 != h2);

    if (id1 == -1 || id2 == -1) {
        cout << -1 << endl;
        return 0;
    }

    ll add = 1LL << 62;

    for (int i = 0; i < magic; i++) {
        if (((id1 + len1 * i) % len2) == id2) {
            add = min(add, id1 + len1 * i);
        }
    }

    if (add == (1LL << 62)) {
        cout << -1 << endl;
    } else {
        cout << ans + add + 1 << endl;
    }


    return 0;
}