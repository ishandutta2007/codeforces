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

const int maxn = 505;
const ll mod = 1000000007;

char f[maxn][maxn];

int* dp[maxn * 3];

int n, m;

ll rec(int a, int b, int c, int d) {
    if (a == n || b == m || c < 0 || d < 0 || f[a][b] != f[c][d] || a > c || b > d) {
        return 0;
    }

    int len = a + b + 1;

    int &res = dp[len][a * len + m - 1 - d];

    if (res != -1) {
        return res;
    }

    res = 0;

    int e = abs(a - c) + abs(b - d);

    if (e == 0) {
        res = 1;
    } else if (e == 1) {
        res = (f[a][b] == f[c][d]);
    } else {
        for (auto d1 : {mp(1, 0), mp(0, 1)}) {
            for (auto d2 : {mp(-1, 0), mp(0, -1)}) {
                if (!(a + d1.fst >= n || b + d1.snd >= m || c + d2.fst < 0 || d + d2.snd < 0)) {
                    res += rec(a + d1.fst, b + d1.snd, c + d2.fst, d + d2.snd);
                    if (res >= mod) {
                        res -= mod;
                    }
                }
            }
        }
    }

    return res;
}


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &f[i][j]);
        }
        scanf("\n");
    }

    for (int i = 1; i < maxn; i++) {
        dp[i] = new int[i * i + 5];
        fill(dp[i], dp[i] + i * i + 5, -1);
    }


    cout << rec(0, 0, n - 1, m - 1) << endl;


    return 0;
}