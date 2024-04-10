#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], lef[maxn], righ[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int i = 1;
    while (i <= n) {
        int j = i + 1;
        while (j <= n && a[j] > a[j - 1]) ++j;
        for (int pos = i; pos < j; ++pos) righ[pos] = j - 1;
        ans = max(ans, j - i);
        i = j;
    }
    i = n;
    while (i >= 1) {
        int j = i - 1;
        while (j > 0 && a[j] < a[j + 1]) --j;
        for (int pos = j + 1; pos <= i; ++pos) lef[pos] = j + 1;
        i = j;
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i - 1] < a[i + 1]) ans = max(ans, i - lef[i - 1] + righ[i + 1] - i);
    }
    cout << ans << '\n';
    return 0;
}