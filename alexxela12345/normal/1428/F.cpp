#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int, int>> st;
int ans = 0;

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.push_back('0');
    int cur = 0;
    st.push_back({0, 0});
    int tot = 0;
    for (char c : s) {
        if (c == '0') {
            for (int i = 0; i < cur; i++) {
                st.push_back({cur - i, 1});
                ans += (cur - i);
            }
            tot += cur * (cur + 1) * (cur + 2) / 6;
            cur = 0;
            st.push_back({0, 1});
        } else {
            cur++;
            int cnt = 0;
            while (!st.empty() && st.back().first <cur) {
                ans -= st.back().first * st.back().second;
                cnt += st.back().second;
                st.pop_back();
            }
            st.push_back({cur, cnt});
            ans += cur * cnt;
        }
        tot += ans;
    }
    tot -= ans;
    cout << tot << endl;
}