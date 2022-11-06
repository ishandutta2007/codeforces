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

int a[111];
int b[111];

int main() {
    init_cin
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<string, int> cn;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cn[s]++;
    }
    int bn = 0;
    for (auto& i : cn) {
        b[bn++] = i.second;
    }
    sort(a, a + n);
    sort(b, b + bn);
    int mn = 0, mx = 0;
    for (int i = 0; i < bn; i++) {
        mn += a[bn - i - 1] * b[i];
        mx += a[n - bn + i] * b[i];
    }
    cout << mn << " " << mx;

    return 0;
}