#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

pair<pair<int, int>, int> a[111111];

int p[111111];
int inT[111111];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        a[i] = {{x, -y}, i};
    }
    sort(a, a + m);
    int kT = 1;
    int x = 0;
    vector<pair<int, int> > ans(m);
    for (int i = 0; i < m; i++) {
        if (a[i].first.second != 0) {
            if (kT == n) {
                cout << -1;
                return 0;
            }
            ans[a[i].second] = {0, kT++};
        } else {
            if (i >= kT * (kT - 1) / 2) {
                cout << -1;
                return 0;
            }
            while (true) {
                if (x == 0) {
                    x = 1;
                }
                while (p[x] == 0 || p[x] <= x) {
                    p[x]++;
                }
                if (p[x] >= kT) {
                    x = (x + 1) % kT;
                } else {
                    break;
                }
            }
            ans[a[i].second] = {x, p[x]++};
        }
    }
    for (auto& i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
    return 0;
}