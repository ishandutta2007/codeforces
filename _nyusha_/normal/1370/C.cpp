#include<bits/stdc++.h>

using namespace std;

int dfs(int n) {
    if (n == 1) return 0;
    if (n % 2 == 1) return 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i % 2 == 1 && dfs(n / i) == 0) return 1;
            if ((n / i) % 2 == 1 && i * i != n && dfs(i) == 0) return 1;
        }
    }
    return (1^dfs(n - 1));
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (dfs(n)) cout << "Ashishgup" << '\n';
        else cout << "FastestFinger" << '\n';
    }
    return 0;
}