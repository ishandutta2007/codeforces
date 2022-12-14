#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int n, a[MAXN];
ll answer;

void add(int idx, int coef) {
    answer += 1LL * coef * idx * (n - idx);
}

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
        if (a[i] != a[i + 1])
            add(i, +1);
    while (m--) {
        int idx, x;
        cin >> idx >> x;
        if (idx > 1 and a[idx] != a[idx - 1])
            add(idx - 1, -1);
        if (idx < n and a[idx] != a[idx + 1])
            add(idx, -1);
        a[idx] = x;
        if (idx > 1 and a[idx] != a[idx - 1])
            add(idx - 1, +1);
        if (idx < n and a[idx] != a[idx + 1])
            add(idx, +1);
        cout << answer + 1LL * n * (n + 1) / 2 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc = 1;
    while (tc--) {
        solve();
    }
}