#include <bits/stdc++.h>

using namespace std;

set <string> st;

int main (int argc, char const *argv[]) {
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n + n; ++i) {
    	st.insert(s);
    	char c = s[n - 1];
    	s.erase(--s.end());
    	s.insert(s.begin(), c);
    }
    cout << st.size() << endl;
    return 0;
}