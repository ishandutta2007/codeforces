#include <bits/stdc++.h>

using namespace std;

char pr['z' + 1];
char to['z' + 1];
bool yes['z' + 1];

string res = "";

void dfs(char c) {
    while ((int) c != -1) {
        res += c;
        c = to[c];
    }
}


int main() {
    memset(pr, -1, sizeof pr);
    memset(to, -1, sizeof to);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < (int) s.size(); j++)
            yes[s[j]] = 1;
        for (int j = 0; j < (int) s.size() - 1; j++)
            to[s[j]] = s[j + 1];
        for (int j = 1; j < (int) s.size(); j++)
            pr[s[j]] = s[j - 1];
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (yes[i] && (int) pr[i] == -1) {
            dfs(i);
        }
    }
    cout << res << endl;
}