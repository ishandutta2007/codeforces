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
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        int x = i % m;
        if (m % 2 == 1) {
            if (x % 2 == 0) {
                cout << (m + 1) / 2 + x / 2;
            } else {
                cout << (m + 1) / 2 - (x + 1) / 2;
            }
        } else {
            if (x % 2 == 0) {
                cout << (m + 1) / 2 - x / 2;
            } else {
                cout << (m + 1) / 2 + (x + 1) / 2;
            }
        }
        cout << "\n";
    }

    return 0;
}