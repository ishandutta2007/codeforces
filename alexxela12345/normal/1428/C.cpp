#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string st;
        for (char c : s) {
            if (c == 'B' && !st.empty() && st.back() == 'A') {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        s = st;
        st.clear();
        for (char c : s) {
            if (c == 'B' && !st.empty()) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        cout << st.size() << '\n';
    }
}