#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
string s[70000 + 100];

int main (){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        set<string> k;
        for (int j = 0; j < s[i].size(); j++)
            for (int z = j; z < s[i].size(); z++) {
                if (k.find(s[i].substr(j, z - j + 1)) == k.end()) {
                    m[s[i].substr(j, z - j + 1)]++;
                    k.insert(s[i].substr(j, z - j + 1));
                }
            }
    }
    for (int i = 0; i < n; i++) {
        bool cur = false;
        for (int z = 1; !cur && z <= s[i].size(); z++) {
            for (int j = 0; j + z - 1 < s[i].size(); j++) {
                if (m[s[i].substr(j, z)] == 1) {
                    cout << s[i].substr(j, z) << endl;
                    cur = true;
                    break;
                }
            }
        }
    }
}