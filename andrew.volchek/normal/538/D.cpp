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

const int maxn = 105;

char a[maxn][maxn];
char b[maxn][maxn];
int c[maxn][maxn];


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s\n", a[i]);
    }

    for (int i = 0; i < 2 * n - 1; i++) {
        fill(b[i], b[i] + 2 * n - 1, '.');
    }

    b[n - 1][n - 1] = 'o';

    auto valid = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n;
    };

    for (int dx = -n - 1; dx <= n - 1; dx++) {
        for (int dy = -n - 1; dy <= n - 1; dy++) {
            if (!dx && !dy) {
                continue;
            }

            bool good = true;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 'o') {
                        good &= !valid(i + dx, j + dy) || a[i + dx][j + dy] != '.';
                    } else if (a[i][j] == 'x') {
                        //good &= !valid(i - dx, j - dy) || a[i - dx][j - dy] == 'o';
                    } else {
                        good &= !valid(i - dx, j - dy) || a[i - dx][j - dy] != 'o';
                    }
                }
            }

            if (good) {
                b[n - 1 + dx][n - 1 + dy] = 'x';

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (a[i][j] == 'o' && valid(i + dx, j + dy)) {
                            c[i + dx][j + dy] = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'x' && !c[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < 2 * n - 1; i++) {
        printf("%s\n", b[i]);
    }


    return 0;
}