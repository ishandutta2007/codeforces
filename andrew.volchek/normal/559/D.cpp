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

const ll maxn = 200005;

ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

ll onSide(const pair<ll,ll> &a, const pair<ll, ll> &b) {
    if (a.fst == b.fst) {
        return abs(a.snd - b.snd) - 1;
    } else if (a.snd == b.snd) {
        return abs(a.fst - b.fst) - 1;
    } else {
        return gcd(abs(a.fst - b.fst), abs(a.snd - b.snd)) - 1;
    }
}

ld p22[300];

ld p2(ll x) {
    return p22[min(x, 70LL)];
}




int main() {
    //srand(time(NULL));

    //freopen("a.in", "r", stdin);

    p22[0] = 1;
    for (int i = 1; i < 100; i++) {
        p22[i] = p22[i - 1] * 2;
    }

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("factory.in", "r", stdin);
    //freopen("factory.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    //n = 100000;

    vector<pair<ll, ll>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        //x = rand(), y = rand();
        a.pb(mp(x, y));
    }


    ld ans = 0.0;

    ld areaAll = 0;
    ld onGAll = 0;

    for (int i = 0; i < n; i++) {
        auto u = a[i], v = a[(i + 1) % n];
        areaAll += (u.fst + v.fst) * (u.snd - v.snd);
        onGAll += onSide(u, v);
    }

    areaAll = abs(areaAll);

    areaAll /= 2;
    onGAll += n;
    ld cntAll = areaAll + 1 - onGAll / 2.0;

    ans = cntAll;

    const int ub = 40;

    for (int i = 0; i < n; i++) {
        ld currS = 0.0, currA = 0.0;
        for (int j = 1; j <= min(n - 2, ub); j++) {
            auto u = a[(i + j - 1) % n];
            auto v = a[(i + j) % n];
            currS += onSide(u, v);
            currA += (u.fst + v.fst) * (u.snd - v.snd) / 2.0;

            ld w = onSide(v, a[i]);
            currS += w;
            currA += (v.fst + a[i].fst) * (v.snd - a[i].snd) / 2.0;

            currS += 1 + j;
            if (j == 1) {
                currS -= w;
            }

            if (j > 1) {

                ld x = abs(currA) + 1 - currS / 2.0;

                x += w;


                ld p = p2(j + 1) - max(1e-30l, (n * (n - 1) / 2.0 + n + 1) / p2(n - (j + 1)));
                p = 1.0 / p;
                p -= max(1e-30l, 1.0 / (p2(n) - n * (n - 1) / 2.0 - n - 1));

                ans -= x * p;
            }

            if (j == 1) {
                currS += w;
            }
            currS -= 1 + j;

            currA -= (v.fst + a[i].fst) * (v.snd - a[i].snd) / 2.0;
            currS -= w;
        }
    }

    cout.precision(12);
    cout << fixed << ans << endl;

    return 0;
}