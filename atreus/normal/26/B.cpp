#include <bits/stdc++.h>

using namespace std;

stack <int> st;

int main() {
	ios_base::sync_with_stdio(false);
    string s;
    int cnt = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(')
            st.push(1);
        if (s[i] == ')'){
            if (st.empty())
                cnt ++;
            else
                st.pop();
        }
    }
    cnt += st.size();
    cout << s.size() - cnt << endl;
}