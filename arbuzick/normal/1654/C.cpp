#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<long long, int> cnt;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
        sum += a;
    }
    vector<long long> st;
    st.push_back(sum);
    bool ch = true;
    while (!st.empty()) {
        // cout << st.back() << endl;
        if (st.back() == 1 && cnt[1] == 0) {
            ch = false;
            break;
        }
        if (cnt[st.back()]) {
            cnt[st.back()]--;
            st.pop_back();
        } else {
            long long val1 = st.back() / 2, val2 = st.back() - val1;
            st.pop_back();
            st.push_back(val1);
            st.push_back(val2);
        }
    }
    if (ch) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}