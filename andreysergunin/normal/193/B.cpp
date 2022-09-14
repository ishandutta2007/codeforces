#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

long long n, u, r;
long long ans = -1e18;
vector<long long> a, b, k, p;

void enumerate(int m, int u, int l) {
    if ((u - m) % 2 == 0) {
        long long cur = 0;
        for (int i = 0; i < n; i++)
            cur += k[i] * a[i];
        ans = max(ans, cur);
    }
    if (u == m)
        return;
    if (l == 0) {
        for (int i = 0; i < n; i++)
            a[i] = a[i] ^ b[i];
        enumerate(m + 1, u, 1);
        for (int i = 0; i < n; i++)
            a[i] = a[i] ^ b[i];
    }
    vector<long long> c(n);
    for (int i = 0; i < n; i++)
        c[i] = a[i];
    for (int i = 0; i < n; i++)
        a[i] = c[p[i]] + r;
    enumerate(m + 1, u, 0);
    for (int i = 0; i < n; i++)
        a[i] = c[i];
}

int main() {
    cin >> n >> u >> r;
    a.resize(n);
    b.resize(n);
    k.resize(n);
    p.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
    enumerate(0, (int)u, 0);
    cout << ans;
}