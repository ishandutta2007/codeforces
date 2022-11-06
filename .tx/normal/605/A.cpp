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
    scid(n);
    rveid(a, n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[--a[i]] = i;
    }
    int mx = 1;
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (p[i] > p[i - 1]) {
            c++;
        } else {
            mx = max(mx, c);
            c = 1;
        }
    }
    cout << n - max(mx, c);
    return 0;
}