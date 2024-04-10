#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    set <char> st;
    for (int i = 0; i < n; i++) {
        if (st.size() == 2 && !st.count(s[i]) ||
            s[i] == 'R' && st.count('L') || s[i] == 'L' && st.count('R') ||
            s[i] == 'U' && st.count('D') || s[i] == 'D' && st.count('U')) {
            ans++;
            st.clear();
            st.insert(s[i]);
        }
        else
            st.insert(s[i]);
    }
    cout << ans;
}