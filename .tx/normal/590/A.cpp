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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    scid(n);
    rveid(a, n);
    a.push_back(a.back());
    n++;
    int ans = 0;
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            c++;
        } else {
            if (c == 1) {
                continue;
            }
            if (c % 2 == 0) {
                ans = max(ans, (c - 2) / 2);
                for (int j = i - 1; j >= i - c; j--) {
                    if (i - j <= c / 2) {
                        a[j] = a[i];
                    } else {
                        a[j] = 1 - a[i];
                    }
                }
            } else {
                ans = max(ans, c / 2);
                for (int j = i - 1; j >= i - c; j--) {
                    a[j] = a[i];
                }
            }
            c = 1;
        }
    }
    a.pop_back();
    n--;
    cout << ans << "\n";
    for (int i : a) {
        cout << i << " ";
    }
    return 0;
}