#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int d[111111][2][3];

int main() {
    init_cin();
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        int c = s[i - 1] - '0';
        d[i][c][0] = max(d[i - 1][c][0], d[i - 1][1 - c][0] + 1);

        d[i][1 - c][0] = d[i - 1][1 - c][0];

        d[i][c][1] = max(d[i - 1][c][1], d[i - 1][1 - c][1] + 1);
        d[i][c][1] = max(d[i][c][1], d[i - 1][c][0] + 1);

        d[i][1 - c][1] = d[i - 1][1 - c][1];

        d[i][c][2] = max(d[i - 1][c][2], d[i - 1][1 - c][2] + 1);
        d[i][c][2] = max(d[i][c][2], d[i - 1][c][1] + 1);

        d[i][1 - c][2] = d[i - 1][1 - c][2];
    }

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            ans = max(ans, d[n][i][j]);
        }
    }
    cout << ans;
    return 0;
}