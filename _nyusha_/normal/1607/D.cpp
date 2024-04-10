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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        string s;
        cin >> s;
        s = "#" + s;
        multiset < int > one, two;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'B') {
                two.insert(a[i]);
            } else {
                one.insert(a[i]);
            }
        }
        if (((int)two.size() && (*two.begin()) <= 0) || ((int)one.size() && (*one.rbegin())) > n) {
            cout << "NO" << '\n';
        } else {
            int cnt = 0, flag = 1;
            for (auto key : two) {
                cnt++;
                if (cnt > key) flag = 0;
            }
            cnt = 0;
            for (auto it = one.end(); it != one.begin(); ) {
                it--;
                cnt++;
                if (n - (*it) + 1 < cnt) {
                    flag = 0;
                }
            }
            if (flag) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}