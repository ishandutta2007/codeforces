#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int a[MAXN], r[MAXN];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        r[i] = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < i)
            r[i - a[i]] = min(r[i - a[i]], i - 1);
    }
    for (int i = n - 1; i >= 1; i--)
        r[i] = min(r[i], r[i + 1]);
    long long answer = 0;
    for (int i = 1; i <= n; i++)
        answer += (r[i] - i + 1);
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}