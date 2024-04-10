#include<bits/stdc++.h>

using namespace std;

int const maxn = 1005;
int a[maxn], answer[maxn];
vector < int > good = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int cur = 1;
        for (int i = 1; i <= n; ++i) answer[i] = 0;
        for (auto key : good) {
            int oks = 0;
            for (int i = 1; i <= n; ++i) {
                if (answer[i] == 0 && a[i] % key == 0) {
                    answer[i] = cur;
                    oks = 1;
                }
            }
            cur += oks;
        }
        cout << cur - 1 << '\n';
        for (int i = 1; i <= n; ++i) cout << answer[i] << ' ';
        cout << '\n';
    }
    return 0;
}