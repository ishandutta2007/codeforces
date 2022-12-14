#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long answer = 0;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            answer = max(answer, 1LL * i * (n - i));
    if (a[0] == a[n - 1])
        answer = n / 2;
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}