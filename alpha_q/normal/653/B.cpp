#include <bits/stdc++.h>

using namespace std;

map <char, vector <string>> M;
set <string> S;
int n, q;

void dfs (string s) {
    if (s.length() == n) {
        S.insert(s);
        return;
    }
    char cc = s[0];
    s.erase(s.begin());
    for (string &p : M[cc]) dfs(p + s);
}

int main() {
    cin >> n >> q;
    while (q--) {
        char c; string ss;
        cin >> ss >> c;
        M[c].push_back(ss);
    }
    dfs("a");
    cout << S.size() << endl;
    return 0;
}