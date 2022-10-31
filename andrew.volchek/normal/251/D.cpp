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

int mb(ll x) {
    for (int i = 63; i >= 0; i--) {
        if (x & (1LL << i)) {
            return i;
        }
    }
}

ll rec(ll x1, ll overall, vector<ll> a) {

    bool any = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            continue;
        }

        any = true;
        int b = mb(a[i]);
        for (int j = 0; j < a.size(); j++) {
            if (i == j) {
                continue;
            }

            if (a[j] & (1LL << b)) {
                a[j] ^= a[i];
            }
        }
    }

    if (!any) {
        return x1;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<ll> notSure;
    for (ll x : a) {
        if (!x) {
            continue;
        }

        int b = mb(x);

        ll s0 = bool(x1 & (1LL << b)) + (bool(overall & (1LL << b)) ^ bool(x1 & (1LL << b)));
        ll s1 = (!bool(x1 & (1LL << b))) + (bool(overall & (1LL << b)) ^ (!bool(x1 & (1LL << b))));

        if (s0 == s1) {
            notSure.pb(x ^ (1LL << b));
        } else if (s1 > s0) {
            x1 ^= x;
        }
    }


    return rec(x1, overall, notSure);
}



int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    //n = 1e5;

    vector<ll> a;
    ll overall = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%I64d", &x);
        //x = (1LL << (i % 62));
        a.pb(x);
        overall ^= x;
    }

    auto b = a;

    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            continue;
        }

        int x = mb(a[i]);

        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (a[j] & (1LL << x)) {
                a[j] ^= a[i];
            }
        }
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    a.resize(64);


    ll bst = rec(0, overall, a);


    ll bstSum = bst + (overall ^ bst);

    reverse(a.begin(), a.end());
    ll x1 = 0;


    for (int i = a.size() - 1; i >= 0; i--) {
        ll x = a[i];
        a.pop_back();
        if (!x) {
            continue;
        }

        ll r0 = rec(x1, overall, a);
        ll r1 = rec(x1 ^ x, overall, a);



        assert(max(r0 + (overall ^ r0), r1 + (overall ^ r1)) == bstSum);
        if (r0 + (overall ^ r0) == bstSum) {

        } else {
            x1 ^= x;
        }
    }


    vector<pair<ll,int>> p;
    vector<ll> p2(n, 0);

    for (int i = 0; i < n; i++) {
        p.pb(mp(b[i], i));
    }

    int u = 0;
    while (true) {
        if (u == p.size()) {
            break;
        }

        sort(p.begin() + u, p.end());
        reverse(p.begin() + u, p.end());
        if (!p[u].fst) {
            break;
        }
        int x = mb(p[u].fst);
        p2[p[u].snd] ^= 1LL << u;
        for (int i = u + 1; i < p.size(); i++) {
            if (p[i].fst & (1LL << x)) {
                p[i].fst ^= p[u].fst;
                p2[p[i].snd] ^= p2[p[u].snd];
            }
        }
        u++;
    }

    vector<int> ans(n, 0);
    ll px1 = x1;
    for (int i = 0; i < u; i++) {
        int x = mb(p[i].fst);
        if (x1 & (1LL << x)) {
            x1 ^= p[i].fst;
            for (int j = 0; j < u; j++) {
                if (p2[p[i].snd] & (1LL << j)) {
                    ans[p[j].snd] ^= 1;
                }
            }
        }
    }
    ll y = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            y ^= b[i];
        }
    }
    assert(y == px1);

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }

        printf("%d", 2 - ans[i]);
    }


    return 0;
}