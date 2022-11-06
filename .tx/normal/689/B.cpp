#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int a[222222];
int d[222222];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        --a[i];
    }
    fill(d, d + n, 1e9);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v + 1 < n && d[v + 1] > d[v] + 1) {
            d[v + 1] = d[v] + 1;
            q.push(v + 1);
        }
        if (v - 1 >= 0 && d[v - 1] > d[v] + 1) {
            d[v - 1] = d[v] + 1;
            q.push(v - 1);
        }
        if (d[a[v]] > d[v] + 1) {
            d[a[v]] = d[v] + 1;
            q.push(a[v]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }

    return 0;
}