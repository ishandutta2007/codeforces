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

typedef long long lint;

using namespace std;

const int MA = 100000;

vector<int> divs[MA + 1];
vector<int> divides[MA + 1];

void initDivs() {
    for (int i = 2; i <= MA; i++) {
        for (int j = i; j <= MA; j += i) {
            divs[j].push_back(i);
        }
    }
}

int d1[MA + 1];
int d2[MA + 1];

int main() {
    initDivs();
    scid(n);
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (auto j : divs[x]) {
            d1[x] = max(d1[x], d2[j] + 1);
        }
        ans = max(ans, d1[x]);
        for (auto j : divs[x]) {
            d2[j] = max(d1[x], d2[j]);
        }
    }
    cout << ans;

    return 0;
}