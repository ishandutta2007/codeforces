#include <bits/stdc++.h>

using namespace std;
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector <bool> flex(2 * n);
    vector <int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        char c;
        cin >> c;
        if (c == '-') {
            int x;
            cin >> x;
            flex[i] = true;
            a[i] = x;
        }
    }
    vector <int> bl(2 * n, -1);
    vector <int> st;
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (!flex[i]) continue;
        while (!st.empty() && a[st.back()] < a[i]) {
            bl[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    vector <vector <pair <int, int>>> all(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        if (flex[i]) {
            all[bl[i] + 1].emplace_back(i - 1, a[i]);
        }
    }
    vector <int> ans;
    set <pair <int, int>> cur;
    for (int i = 0; i < 2 * n; ++i) {
        if (flex[i]) {

        } else {
            for (auto j : all[i]) {
                cur.insert(j);
            }
            if (cur.empty() || cur.begin()->first < i) {
                cout << "NO";
                return 0;
            }
            ans.push_back(cur.begin()->second);
            cur.erase(cur.begin());
        }
    }
    cout << "YES\n";
    for (int i : ans) cout << i << " ";
}