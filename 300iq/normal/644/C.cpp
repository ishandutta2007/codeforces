#include <bits/stdc++.h>

using namespace std;

map <string, set <string> > h;
map <set <string>, vector <string> > res;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string hostname = "";
        int uk = 7;
        while (uk < (int) s.size() && s[uk] != '/') {
            hostname += s[uk];
            uk++;
        }
        if (uk == s.size()) {
            h[hostname].insert("-1");
        } else {
            string path = "";
            while (uk < (int) s.size()) {
                path += s[uk];
                uk++;
            }
            h[hostname].insert(path);
        }

    }
    for (auto f : h) {
        res[f.second].push_back(f.first);
    }
    vector <vector <string> > g;
    for (auto f : res) {
        if (f.second.size() != 1)
            g.push_back(f.second);
    }
    cout << g.size() << endl;
    for (int i = 0; i < (int) g.size(); i++) {
        for (int j = 0; j < (int) g[i].size(); j++) {
            cout << "http://" << g[i][j] << " ";
        }
        cout << endl;
    }
}