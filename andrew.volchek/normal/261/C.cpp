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

ll f[60][60];



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

    ll n, t;
    cin >> n >> t;

    f[0][0] = 1;
    for (int i = 1; i < 60; i++) {
        f[i][0] = 1;
        for (int j = 1; j < 60; j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        }
    }

    ll ans = 0;
n++;
if (t==1)
ans--;

    int lv = 0;
    ll len = 1;
    while (n) {
        while (n < len) {
            if (n > len / 2) {
                for (int i = 0; i < 55; i++) {
                    if ((1LL << i) == t) {
                        ans += f[lv - 1][i];
                    }
                }
                if (t & 1) {
                    cout << ans << endl;
                    return 0;
                }
                t /= 2;
                n -= len / 2;
                lv--;
                len /= 2;
            } else {
                lv--;
                len /= 2;
            }
        }

        assert(len > 0);

        for (int i = 0; i < 55; i++) {
            if ((1LL << i) == t) {
                ans += f[lv][i];
            }
        }

        n -= len;
        lv++;
        len += len;
    }

    cout << ans << endl;

    return 0;
}