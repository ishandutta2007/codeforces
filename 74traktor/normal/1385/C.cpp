#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int i = n - 1;
        while (i >= 1 && a[i] >= a[i + 1]) i--;
        while (i >= 1 && a[i] <= a[i + 1]) i--;
        cout << i << '\n';
    }
    return 0;
}