#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int d[26][26];

int main() {
    init_cin
    int n;
    cin >> n;
    memset(d, -1, sizeof(int) * 26 * 26);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = s[0] - 'a';
        int y = s.back() - 'a';
        for (int j = 0; j < 26; j++) {
            if (d[j][x] != -1) {
                d[j][y] = max(d[j][y], (const int &) (d[j][x] + s.length()));
            }
        }
        d[x][y] = max(d[x][y], (const int &) s.length());
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = max(ans, d[i][i]);
    }
    cout << ans;

    return 0;
}