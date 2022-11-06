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

int c[55];
int a[55][55];
pair<int, int> p[5555];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(c[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c[i]; j++) {
            scid(x);
            p[--x] = {i, j};
            a[i][j] = x;
        }
    }

    int x = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c[i]; j++, x++) {
            if (a[i][j] == x) {
                continue;
            }
            ans.push_back(i);
            ans.push_back(j);
            ans.push_back(p[x].first);
            ans.push_back(p[x].second);
            int t = a[i][j];
            swap(a[i][j], a[p[x].first][p[x].second]);
            p[t] = p[x];
            p[x] = {i, j};

        }
    }

    cout << ans.size() / 4 << "\n";
    for (int i = 0; i < ans.size(); i += 4) {
        printf("%d %d %d %d\n", ans[i] + 1, ans[i + 1] + 1, ans[i + 2] + 1, ans[i + 3] + 1);
    }


    return 0;
}