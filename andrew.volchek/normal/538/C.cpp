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
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    if (m == 1) {
        int d, h;
        scanf("%d %d", &d, &h);
        cout << max(h + d - 1, h + n - d) << endl;
        return 0;
    }

    int ans = 0;
    int prvH, prvD;
    for (int i = 0; i < m; i++) {
        int d, h;
        scanf("%d %d", &d, &h);
        ans = max(ans, h);

        if (i == 0) {
            ans = max(ans, h + d - 1);
        } else {
            if (i == m - 1) {
                ans = max(ans, h + n - d);
            }

            if (abs(prvH - h) > abs(prvD - d)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }

            ans = max(ans, max(prvH, h) + (abs(prvD - d) - abs(prvH - h)) / 2);
        }

        prvD = d, prvH = h;
    }

    cout << ans << endl;

    return 0;
}