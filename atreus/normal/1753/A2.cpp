#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != 0)
                sum++;
        }
        if (sum % 2 != 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<pair<int,int>> ans;
        int last = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                if (last == 0)
                    ans.push_back({i, i});
                continue;
            }
            if (last == 0) {
                last = i;
                continue;
            }
            if ((a[i] == a[last] && last % 2 == i % 2) || (a[i] != a[last] && last % 2 != i % 2)) {
                if (i % 2 == last % 2) {
                    ans.push_back({last, i - 2});
                    ans.push_back({i - 1, i});
                }
                else {
                    ans.push_back({last, i - 1});
                    ans.push_back({i, i});
                }
            } else {
                ans.push_back({last, i});
            }
            last = 0;
        }
        cout << ans.size() << '\n';
        for (auto [L, R] : ans)
            cout << L << " " << R << '\n';
        continue;
    }
}