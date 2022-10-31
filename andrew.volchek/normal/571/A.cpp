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

    ll a[3], p;
    cin >> a[0] >> a[1] >> a[2] >> p;
    ll ans = (p + 1) * (p + 2) * (p + 3) / 6;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= p; j++) {
            ll x = a[i] + j - (a[(i + 1) % 3] + a[(i + 2) % 3]);
            x = min(x, p - j);
            if (x < 0) {
               continue;
            }

            ans -= (x + 1) * (x + 2) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}