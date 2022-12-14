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
        for (int i = 1; i <= n; i += 2) {
            if (a[i] == a[i + 1]) {
                ans.push_back({i, i + 1});
            }
            else {
                ans.push_back({i, i});
                ans.push_back({i + 1, i + 1});
            }
        }
        cout << ans.size() << '\n';
        for (auto [L, R] : ans)
            cout << L << " " << R << '\n';
        continue;
        int L = 1;
        int last = 0;
        vector<int> st;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0)
                continue;
            if (last == 0) {
                last = i;
                continue;
            }
            if ((a[i] == a[last] && last % 2 == i % 2) || (a[i] != a[last] && last % 2 != i % 2)) {
                if ((i - L) % 2 == 0) {
                    st.push_back(i - 1);
                    L = i - 1;
                }
                else {
                    st.push_back(i);
                    L = i;
                }
            }
            last = 0;
        }
        cout << st.size() + 1 << '\n';
        L = 1; 
        for (auto i : st) {
            cout << L << " " << i - 1 << '\n';
            L = i;
        }
        cout << L << " " << n << '\n';
    }
}