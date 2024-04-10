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

int a[2][55];
int b[55];
int ps[2][55];

int main() {
    scid(n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n - 1; j++) {
            sci(a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        sci(b[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        ps[0][i] = a[0][i];
        if (i > 0) {
            ps[0][i] += ps[0][i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        ps[1][i] = a[1][i];
        if (i != n - 2) {
            ps[1][i] += ps[1][i + 1];
        }
    }
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int x = i == 0 ? 0 : ps[0][i - 1];
        int y = i == n - 1 ? 0 : ps[1][i];
        q.push(-(x + y + b[i]));
    }
    int ans = -q.top();
    q.pop();
    ans -= q.top();
    cout << ans;


    return 0;
}