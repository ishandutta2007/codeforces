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

const int maxn = 2e6 + 5;

int a[maxn];
int was[maxn];

int b[maxn][23];


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

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; i++) {
        fill(b[i], b[i] + 23, -1);
        if (i) {
            for (int j = 0; j < 23; j++) {
                b[i][j] = b[i - 1][j];
            }
        }

        for (int j = 0; j < 23; j++) {
            if (a[i] & (1 << j)) {
                b[i][j] = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> c;
        for (int j = 0; j < 23; j++) {
            if (b[i][j] != -1) {
                c.pb(mp(b[i][j], j));
            }
        }
        sort(c.begin(), c.end());
        reverse(c.begin(), c.end());
        int x = 0;
        if (a[i] == 0) {
            was[0] = 1;
        }
        for (int j = 0; j < c.size(); j++) {
            int h = j;
            while (h < c.size() && c[h].fst == c[j].fst) {
                x |= 1 << c[h].snd;
                h++;
            }
            was[x] = 1;
            j = h - 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < maxn; i++) {
        ans += was[i];
    }

    cout << ans << endl;

    return 0;
}