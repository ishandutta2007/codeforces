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

ld f[55][55];

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
    cin >> n;
    vector<int> a;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        a.pb(x);
    }
    int m;
    cin >> m;

    if (s <= m) {
        cout << n << endl;
        return 0;
    }

    ld ans = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 55; j++) {
            fill(f[j], f[j] + 55, 0);
        }
        f[0][0] = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = n; k >= 1; k--) {
                for (int h = m; h >= a[j]; h--) {
                    f[h][k] += f[h - a[j]][k - 1];
                }
            }
        }


        for (int j = max(0, m - a[i] + 1); j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                ld c = f[j][k];

                int p1 = 1, p2 = k + 1;
                while (p1 <= n - 1 - k || p2 <= n) {
                    if (p1 <= n - 1 - k) {
                        c *= p1;
                        p1++;
                    }

                    if (p2 <= n) {
                        c /= p2;
                        p2++;
                    }
                }

                ans += c * k;
            }
        }
    }



    cout.precision(10);
    cout << fixed << ans << endl;
    return 0;
}