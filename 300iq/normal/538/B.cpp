#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector <string> ans;
    bool logic = true;
    while (logic) {
        logic = false;
        string t = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && t.size() != 0)
                t += '0';
            else if (s[i] != '0')
                t += '1', logic = 1;
        }
        for (int i = 0; i < n; i++)
            if (s[i] != '0')
                s[i]--;
        if (t != "")
            ans.push_back(t);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}