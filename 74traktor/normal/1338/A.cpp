#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int a[maxn];

int check(int n, int t) {
    int lst = (1ll << t) - 1 + a[n];
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] > lst) return 0;
        lst = min(a[i] + (1ll << t) - 1, lst);
    }
    return 1;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int lef = -1, righ = 62;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (check(n, mid)) righ = mid;
            else lef = mid;
        }
        cout << righ << '\n';
    }
    return 0;
}