#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int main() {
    int x;
    cin >> x;
    string s;
    cin >> s >> s;
    int d[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (s == "week") {
        int cur = 4;
        int ans = 0;
        x--;
        for (int i = 0; i < 366; i++) {
            if (cur == x) {
                ans++;
            }
            cur++;
            cur %= 7;
        }
        cout << ans;
    } else {
        int cm = 1;
        int cd = 0;
        x--;
        int ans = 0;
        for (int i = 0; i < 366; i++) {
            if (cd == x) {
                ans++;
            }
            cd++;
            if (cd == d[cm]) {
                cm++;
                cd = 0;
            }
        }
        cout << ans;
    }

    return 0;
}