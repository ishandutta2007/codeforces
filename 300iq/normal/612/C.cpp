#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<') {
            b++;
        } else {
            b--;
            if (b < 0) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    if (b != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    stack <char> st;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.top() != '(') {
                ans++;
            }
            st.pop();
        } else if (s[i] == '}') {
            if (st.top() != '{') {
                ans++;
            }
            st.pop();
        } else if (s[i] == ']') {
            if (st.top() != '[') {
                ans++;
            }
            st.pop();
        } else if (s[i] == '>') {
            if (st.top() != '<') {
                ans++;
            }
            st.pop();
        }
    }
    cout << ans << endl;
}