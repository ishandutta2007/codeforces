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
    vector<int> a;
    int s = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        a.push_back(x);
        s += x;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = s / (n - i);
        s -= b[i];
    }
    sort(a.begin(), a.end());
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans / 2;


    return 0;
}