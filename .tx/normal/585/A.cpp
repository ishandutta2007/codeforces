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
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

lint v[4444];
lint d[4444];
lint p[4444];

int main() {
    init_cin();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> d[i] >> p[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (p[i] < 0) {
            for (int j = i + 1; j < n; j++) {
                p[j] -= d[i];
            }
        } else {
            ans.push_back(i);
            lint x = 0;
            for (int j = i + 1; j < n && v[i] > 0; j++) {
                if (p[j] - x >= 0) {
                    p[j] -= v[i];
                    v[i]--;
                } else {
                    x += d[j];
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    return 0;
}