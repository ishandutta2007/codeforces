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

int d[5555];
int p[5555];
int ans[5555];

int main() {
    sciiid(n, w, h);
    vector<pair<int, pair<int, int> > > a;
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        if (x > w && y > h) {
            a.push_back({x, {y, i}});
        }
    }
    sort(a.rbegin(), a.rend());
    n = a.size();
    int md = 0;
    int mp = -1;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j].first > a[i].first && a[j].second.first > a[i].second.first) {
                if (d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                    p[i] = j;
                }
            }
        }
        if (d[i] > md) {
            md = d[i];
            mp = i;
        }
    }
    cout << md << "\n";
    for (int i = 0; i < md; i++) {
        cout << a[mp].second.second + 1 << " ";
        mp = p[mp];
    }

    return 0;
}