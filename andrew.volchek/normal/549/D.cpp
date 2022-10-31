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
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>

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
#define y1 _y1

const ld pi = 3.14159265359;

template < typename T >
T abs(T x) {
    return x > 0 ? x : -x;
}

template < typename T >
T sqr(T x) {
    return x * x;
}

const int maxn = 105;
ll s[maxn][maxn];
char a[maxn][maxn];

int main() {
   // freopen("a.in", "r", stdin);
    int n, m;
    scanf("%d %d\n", &n, &m);
    //n = 100, m = 100;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &a[i][j]);
            //a[i][j] = (i + j) % 2 == 1 ? 'W' : 'B';
        }
        scanf("\n");
    }

    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            ll need = a[i][j] == 'W' ? 1 : -1;
            if (need == s[i][j]) {
                continue;
            } else {
                ll add = -s[i][j] + need;
                ans++;
                for (int x = i; x >= 0; x--) {
                    for (int y = j;  y >= 0; y--) {
                        s[x][y] += add;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}