#include<bits/stdc++.h>

using namespace std;

int const maxn = 10005;
int a[maxn];

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
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        set < int > used;
        for (int i = 1; i <= n; ++i) used.insert(a[i]);
        if ((int)used.size() > k) {
            cout << -1 << '\n';
            continue;
        }
        while ((int)used.size() < k) {
            for (int i = 1; i <= n; ++i) {
                if (used.find(i) == used.end()) {
                    used.insert(i);
                    break;
                }
            }
        }
        cout << n * (int)used.size() << '\n';
        for (int i = 1; i <= n; ++i) {
            for (auto key : used) cout << key << " ";
        }
        cout << '\n';
    }
    return 0;
}