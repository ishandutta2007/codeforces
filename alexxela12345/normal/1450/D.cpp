//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> leq(n), geq(n);
    iota(geq.rbegin(), geq.rend(), 1);
    vector<int> left(n);
    vector<int> right(n);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.back()] > arr[i]) {
            right[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while (!st.empty()) {
        right[st.back()] = n;
        st.pop_back();
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.back()] > arr[i]) {
            left[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while (!st.empty()) {
        left[st.back()] = -1;
        st.pop_back();
    }
    for (int i = 0; i < n; i++) {
        leq[arr[i] - 1] = max(leq[arr[i] - 1], right[i] - left[i] - 1);
    }
    for (int i = 1; i < n; i++) {
        leq[i] = min(leq[i], leq[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (leq[i] >= geq[i]) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
}