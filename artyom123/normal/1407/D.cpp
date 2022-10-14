#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto &c : h) cin >> c;
    vector<int> dp(n, INF);
    dp[0] = 0;
    vector<int> left_more(n), left_less(n), right_more(n), right_less(n);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++) {
        while (st.size() && h[st.top()] <= h[i]) {
            right_more[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        right_more[st.top()] = -1;
        st.pop();
    }
    st.push(0);
    for (int i = 1; i < n; i++) {
        while (st.size() && h[st.top()] >= h[i]) {
            right_less[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        right_less[st.top()] = -1;
        st.pop();
    }
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        while (st.size() && h[st.top()] <= h[i]) {
            left_more[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        left_more[st.top()] = -1;
        st.pop();
    }
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        while (st.size() && h[st.top()] >= h[i]) {
            left_less[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        left_less[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < n; i++) {
        if (left_more[i] != -1) dp[i] = min(dp[i], dp[left_more[i]] + 1);
        if (left_less[i] != -1) dp[i] = min(dp[i], dp[left_less[i]] + 1);
        if (right_more[i] != -1) dp[right_more[i]] = min(dp[right_more[i]], dp[i] + 1);
        if (right_less[i] != -1) dp[right_less[i]] = min(dp[right_less[i]], dp[i] + 1);
    }
    cout << dp[n - 1];
    return 0;
}