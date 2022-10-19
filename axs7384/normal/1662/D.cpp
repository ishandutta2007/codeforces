#include <bits/stdc++.h>
using namespace std;

pair<int, string> get(const string& s) {
    int b = 0;
    string vs;
    for (char c : s)  {
        if (c == 'B')
            b++;
        else if (!vs.empty() && vs.back() == c)
            vs.pop_back();
        else 
            vs.push_back(c);
    }
    return { b % 2 , vs };
}

int main(void) {
    int T; cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        if (get(s) == get(t))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}