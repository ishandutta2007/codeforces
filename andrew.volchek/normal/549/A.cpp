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

const int maxn = 1005;
char a[maxn][maxn];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &a[i][j]);
        }
        scanf("\n");
    }

    vector<char> need({'f', 'a', 'c', 'e'});
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            vector<int> was(4, 0);
            for (int dx = 0; dx < 2; dx++) {
                for (int dy = 0; dy < 2; dy++) {
                    for (int h = 0; h < 4; h++) {
                        was[h] |= (a[i + dx][j + dy] == need[h]);
                    }
                }
            }
            bool good = true;
            for (int h = 0; h < 4; h++) {
                good &= was[h];
            }
            ans += good;
        }
    }

    cout << ans << endl;

    return 0;
}