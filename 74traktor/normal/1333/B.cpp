#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn], b[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt0 = 0, cnt1 = 0, cnt2 = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 1; i <= n; ++i) {
            a[i]++;
            if (a[i] == 0) cnt0++;
            else if (a[i] == 1) cnt1++;
            else cnt2++;
        }
        int ok = 1;
        for (int i = n; i >= 1; --i) {
            if (a[i] == 0) cnt0--;
            else if (a[i] == 1) cnt1--;
            else cnt2--;
            if (b[i] > a[i] - 1 && cnt2 == 0) ok = 0;
            if (b[i] < a[i] - 1 && cnt0 == 0) ok = 0;
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}