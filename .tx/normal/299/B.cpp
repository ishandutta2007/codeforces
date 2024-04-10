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

bool can[333333];

int main() {
    init_cin
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    can[0] = true;
    int k1 = 0;
    for (int i = 1; i <= k; i++) {
        if (s[i] == '.') {
            can[i] = true;
            k1++;
        }
    }
    for (int i = k + 1; i < n; i++) {
        if (s[i] == '.' && k1 > 0) {
            can[i] = true;
            k1++;
        }
        if (can[i - k]) {
            k1--;
        }
    }
    cout << (can[n - 1] ? "YES" : "NO");
    return 0;
}