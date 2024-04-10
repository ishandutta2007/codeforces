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

char a[111][111];

int main() {
    int n, m;
    char c;
    scanf("%d %d %c\n", &n, &m, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    set<char> s;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == c) {
                for (int k = 0; k < 4; k++) {
                    s.insert(a[i + dx[k]][j + dy[k]]);
                }
            }
        }
    }
    s.erase('.');
    s.erase(0);
    s.erase(c);
    cout << s.size();
    return 0;
}