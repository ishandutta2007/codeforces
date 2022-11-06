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

int a, b;
map<int, int> s;
int cc[111111];
int p[111111];
bool canA[111111];
bool canB[111111];

void dfs(int v, int c) {
    cc[v] = c;
    int to[2] {a - p[v], b - p[v]};
    for (int i = 0; i < 2; i++) {
        int x = to[i];
        if (s.find(x) != s.end()) {
            int y = s[x];
            if (cc[y] == 0) {
                dfs(y, c);
            }
        }
    }
}

int ans[111111];

int main() {
    scid(n);
    scii(a, b);

    for (int i = 0; i < n; i++) {
        sci(p[i]);
        s[p[i]] = i;
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (cc[i] == 0) {
            dfs(i, ++c);
        }
    }

    memset(canA, true, sizeof(bool) * 111111);
    memset(canB, true, sizeof(bool) * 111111);

    for (int i = 0; i < n; i++) {
        if (s.find(a - p[i]) == s.end()) {
            canA[cc[i]] = false;
        }

        if (s.find(b - p[i]) == s.end()) {
            canB[cc[i]] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (canA[cc[i]]) {
            ans[i] = 0;
        } else if (canB[cc[i]]) {
            ans[i] = 1;
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}