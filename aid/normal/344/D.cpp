#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    stack<char> st;
    for(size_t i = 0; i < s.length(); i++) {
        if(st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    }
    if(st.empty())
        cout << "Yes\n";
    else
        cout << "No\n";
}