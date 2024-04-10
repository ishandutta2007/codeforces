#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
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

char s[4444];

int main() {
    scid(a);
    scanf("%s", s);
    int n = strlen(s);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += s[j] - '0';
            m[sum]++;
        }
    }
    if (a == 0) {
        lint ans = 2LL * m[0] * n * (n + 1) / 2 - 1LL * m[0] * m[0];
        cout << ans;
        return 0;
    }
    lint ans = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            ans += 1LL * m[i] * m[a / i];
            if (i * i != a) {
                ans += 1LL * m[a / i] * m[i];
            }
        }
    }
    cout << ans;
    return 0;
}