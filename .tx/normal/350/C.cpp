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

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

int main() {
    scid(n);
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = {x, y};
    }
    random_shuffle(a.begin(), a.end());
    sort(a.begin(), a.end(), cmp);
    int kop = 0;
    for (auto i : a) {
        if (i.first == 0 || i.second == 0) {
            kop += 4;
        } else {
            kop += 6;
        }
    }
    printf("%d\n", kop);
    for (auto i : a) {
        if (i.first != 0) {
            printf("1 %d %c\n", abs(i.first), i.first > 0 ? 'R' : 'L');
        }
        if (i.second != 0) {
            printf("1 %d %c\n", abs(i.second), i.second > 0 ? 'U' : 'D');
        }
        puts("2");
        if (i.second != 0) {
            printf("1 %d %c\n", abs(i.second), i.second > 0 ? 'D' : 'U');
        }
        if (i.first != 0) {
            printf("1 %d %c\n", abs(i.first), i.first > 0 ? 'L' : 'R');
        }
        puts("3");
    }

    return 0;
}