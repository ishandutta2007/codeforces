#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

mt19937 gen(time(0));

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &c : a) cin >> c;
    vector<vector<int>> left(n, vector<int>(m)), right(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        stack<int> st;
        for (int j = 0; j < m; j++) {
            while (!st.empty() && a[i][st.top()] != a[i][j]) {
                right[i][st.top()] = j - st.top();
                st.pop();
            }
            st.push(j);
        }
        while (!st.empty()) {
            right[i][st.top()] = m - st.top();
            st.pop();
        }
        for (int j = m - 1; j >= 0; j--) {
            while (!st.empty() && a[i][st.top()] != a[i][j]) {
                left[i][st.top()] = st.top() - j;
                st.pop();
            }
            st.push(j);
        }
        while (!st.empty()) {
            left[i][st.top()] = st.top() + 1;
            st.pop();
        }
    }
    vector<vector<int>> dpup(n, vector<int>(m, 1)), dpdown(n, vector<int>(m, 1));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i - 1][j] != a[i][j]) continue;
            dpup[i][j] = min(min(left[i][j], right[i][j]) * 2 - 1, dpup[i - 1][j] + 2);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (a[i + 1][j] != a[i][j]) continue;
            dpdown[i][j] = min(min(left[i][j], right[i][j]) * 2 - 1, dpdown[i + 1][j] + 2);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += min(dpup[i][j], dpdown[i][j]) / 2 + 1;
        }
    }
    cout << ans;
    return 0;
}