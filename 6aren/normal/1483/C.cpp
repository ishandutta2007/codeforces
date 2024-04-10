#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 300005;

int it[4 * N];

void update(int k, int l, int r, int id, int val) {
    if (l > id || r < id) return;
    if (l == r && l == id) {
        it[k] = val;
        return;
    } 
    int mid = (l + r) / 2;
    update(2 * k, l, mid, id, val);
    update(2 * k + 1, mid + 1, r, id, val);
    it[k] = max(it[2 * k], it[2 * k + 1]);
}

int get(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return -1e18;
    if (l >= u && r <= v) return it[k];
    int mid = (l + r) / 2;
    return max(get(2 * k, l, mid, u, v), get(2 * k + 1, mid + 1, r, u, v));
}

int n;
int h[N], b[N];
int dp[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    stack<tuple<int, int, int>> st;
    set<tuple<int, int, int>> mx_in_st;
    st.push({0, -2e9, 0});
    // {beauti, height, id}
    for (int i = 1; i <= n; i++) {
        while (true) {
            auto foo = st.top();
            if (get<1>(foo) > h[i]) {
                st.pop();
                mx_in_st.erase(foo);
            } else break;
        }
        int baz = get(1, 0, n, get<2>(st.top()), i - 1);
        // cout << baz << endl;
        st.push(make_tuple(baz + b[i], h[i], i));
        mx_in_st.insert(make_tuple(baz + b[i], h[i], i));
        dp[i] = get<0>(*mx_in_st.rbegin());
        update(1, 0, n, i, dp[i]);
        // cout << dp[i] << ' ';
    }
    // cout << endl;
    cout << dp[n] << endl;

    return 0;
}