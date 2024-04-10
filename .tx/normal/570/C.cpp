#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

char s[333333];

int main() {
    sciid(n, m);
    scanf("%s", s);
    int t = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '.' && s[i - 1] == '.') {
            t++;
        }
    }
    for (; m-- > 0; ) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        --x;
        if (s[x] == '.') {
            if (x > 0 && s[x - 1] == '.') {
                t--;
            }
            if (x + 1 < n && s[x + 1] == '.') {
                t--;
            }
        }
        s[x] = c;
        if (c == '.') {
            if (x > 0 && s[x - 1] == '.') {
                t++;
            }
            if (x + 1 < n && s[x + 1] == '.') {
                t++;
            }
        }
        printf("%d\n", t);
    }

    return 0;
}