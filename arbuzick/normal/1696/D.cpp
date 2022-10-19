#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> st;
    vector<int> nxt_mn(n, n), nxt_mx(n, n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] < a[i]) {
            nxt_mx[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] > a[i]) {
            nxt_mn[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int u = nxt_mx[v];
        while (u < nxt_mn[v] && dist[u] == -1) {
            dist[u] = dist[v] + 1;
            q.push(u);
            u = nxt_mx[u];
        }
        u = nxt_mn[v];
        while (u < nxt_mx[v] && dist[u] == -1) {
            dist[u] = dist[v] + 1;
            q.push(u);
            u = nxt_mn[u];
        }
    }
    cout << dist[n - 1] << '\n';
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