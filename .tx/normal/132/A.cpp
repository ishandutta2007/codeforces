#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
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

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int rev(int x) {
    int res = 0;
    for (int i = 0; i < 8; i++) {
        res <<= 1;
        res |= x & 1;
        x >>= 1;
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    int last = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        int x = rev(s[i]);
        cout << (last - x + 256) % 256 << "\n";
        last = x;
    }


    return 0;
}