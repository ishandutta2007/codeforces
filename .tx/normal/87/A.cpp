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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    sciid(a, b);
    string ans[2] {"Dasha", "Masha"};
    if (a > b) {
        swap(a, b);
        swap(ans[0], ans[1]);
    }
    int g = gcd(a, b);
    a /= g;
    b /= g;
    lint tb = 1LL * a * (a + 1) / 2;
    lint ta = 1LL * a * b - tb;
    if (ta == tb) {
        cout << "Equal";
    } else if (ta > tb) {
        cout << ans[0];
    } else {
        cout << ans[1];
    }


    return 0;
}