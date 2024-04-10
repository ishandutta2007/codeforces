#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int INF = 1e9 + 1;

vector<int> get(char c) {
    int n = 0;
    if (c <= '9') {
        n = c - '0';
    } else {
        n = 10 + c - 'A';
    }
    vector<int> ans;
    while (n > 0) {
        ans.push_back(n & 1);
        n >>= 1;
    }
    while (ans.size() < 4) {
        ans.push_back(0);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n / 4; j++) {
            char c = s[j];
            auto tmp = get(c);
            for (int l = j * 4; l < (j + 1) * 4; l++) {
                a[i][l] = tmp[l - j * 4];
            }
        }
    }
    vector<int> next_h(n);
    vector<int> next_v(n);
    stack <int> st;
    vector<int> tmp1;
    vector<int> tmp2;
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(i);
            continue;
        }
        tmp1.clear();
        tmp2.clear();
        for (int j = 0; j < n; j++) {
            tmp1.push_back(a[i - 1][j]);
            tmp2.push_back(a[i][j]);
        }
        if (tmp1 == tmp2) {
            st.push(i);
        } else {
            while (!st.empty()) {
                next_h[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        next_h[st.top()] = n;
        st.pop();
    }
    for (int j = 0; j < n; j++) {
        if (st.empty()) {
            st.push(j);
            continue;
        }
        tmp1.clear();
        tmp2.clear();
        for (int i = 0; i < n; i++) {
            tmp1.push_back(a[i][j - 1]);
            tmp2.push_back(a[i][j]);
        }
        if (tmp1 == tmp2) {
            st.push(j);
        } else {
            while (!st.empty()) {
                next_v[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
    }
    while (!st.empty()) {
        next_v[st.top()] = n;
        st.pop();
    }
    int ans = 1;
    for (int x = 2; x <= n; x++) {
        if (n % x != 0) {
            continue;
        }
        bool f = true;
        for (int i = 0; i < n; i += x) {
            if (next_h[i] < i + x) {
                f = false;
                break;
            }
        }
        for (int i = 0; i < n; i += x) {
            if (next_v[i] < i + x) {
                f = false;
                break;
            }
        }
        if (f) ans = x;
    }
    cout << ans;
    return 0;
}