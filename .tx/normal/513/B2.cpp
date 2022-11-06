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

int main() {
    init_cin();
    int n;
    lint k;
    cin >> n >> k;
    k--;
    vector<int> ans(n);
    int r = n - 1;
    int l = 1;
    for (int i = 0; i < n && l <= n; i++) {
        while (l < n && (1LL << (n - 1 - l)) <= k) {
            k -= 1LL << (n - 1 - l);
            ans[r--] = l++;
        }
        ans[i] = l++;
    }
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;

}