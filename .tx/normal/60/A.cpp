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

int main() {
    init_cin
    int n, m;
    cin >> n >> m;
    vector<bool> can(n, true);
    while (m-- > 0) {
        string s, t;
        int x;
        cin >> s >> s >> s >> t >> x;
        if (s == "left") {
            for (int i = x - 1; i < n; i++) {
                can[i] = false;
            }
        } else {
            for (int i = 0; i < x; i++) {
                can[i] = false;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (can[i]) {
            ans++;
        }
    }
    cout << (ans == 0 ? -1 : ans);

    return 0;
}