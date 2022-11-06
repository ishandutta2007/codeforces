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

vector<int> d[111111];
int cd[222];

int main() {
    scid(n);
    rveid(a, n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        d[a[i]].push_back(x);
        s += x;
    }
    int ans = 1e9;
    for (int i = 1; i < 111111; i++) {
        if (d[i].empty()) {
            continue;
        }
        int x = d[i].size() - 1;
        int t = s;
        for (int j : d[i]) {
            t -= j;
        }
        int j = 200;
        while (x > 0 && j > 0) {
            int tt = min(x, cd[j]);
            t -= j * tt;
            x -= tt;
            j--;
        }
        ans = min(ans, t);
        for (int j : d[i]) {
            cd[j]++;
        }
    }
    cout << ans;
    return 0;
}