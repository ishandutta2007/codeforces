#include <bits/stdc++.h>

using namespace std;

set <char> st;
string s;

int main()
{
    getline(cin, s);
    for (int i = 0; i < (int)s.size(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
            st.insert(s[i]);
    }
    cout << st.size();
    return 0;
}