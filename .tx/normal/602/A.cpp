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

int main() {
    sciid(n, bx);
    rveid(a, n);
    lint p = 1;
    lint aa = 0;
    for (int i = n - 1; i >= 0; i--) {
        aa += a[i] * p;
        p *= bx;
    }
    sciid(m, by);
    rveid(b, m);
    p = 1;
    lint bb = 0;
    for (int i = m - 1; i >= 0; i--) {
        bb += b[i] * p;
        p *= by;
    }
    cout << (aa == bb ? "=" : (aa < bb ? "<" : ">"));
    return 0;
}