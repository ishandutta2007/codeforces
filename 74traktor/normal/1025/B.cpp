#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e7 + 5;
vector < pair < int, int > > a;
int ok[maxn];

void go(int x) {
    if (x == 1) return;
    if (x < maxn && ok[x] == 1) return;
    for (auto key : a) {
        if (key.first % x == 0 || key.second % x == 0) continue;
        return;
    }
    cout << x << '\n';
    exit(0);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        a.push_back({x, y});
    }
    for (int j = 2; j < maxn; ++j) {
        if (ok[j] == 0) {
            if (j > 10000) continue;
            for (int z = j * j; z < maxn; z += j) ok[z] = 1;
        }
    }
    for (int j = 1; j * j <= a[0].first; ++j) {
        if (a[0].first % j == 0) go(j), go(a[0].first / j);
    }
    for (int j = 1; j * j <= a[0].second; ++j) {
        if (a[0].second % j == 0) go(j), go(a[0].second / j);
    }
    cout << -1 << '\n';
    return 0;
}