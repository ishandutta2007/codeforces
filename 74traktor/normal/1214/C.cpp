#include <bits/stdc++.h>

using namespace std;

bool ok(string s) {
    int bal = 0;
    for (auto c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) return false;
    }
    return bal == 0;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int n;
    cin >> n;
    cin >> s;
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') pos1 = i;
        if (s[i] == ')' && pos2 == -1) pos2 = i;
    }
    string s1 = "", s2 = "";
    if (pos1 == -1 || pos2 == -1) {
        cout << "No" << '\n';
        return 0;
    }
    s1 += '(';
    for (int i = 0; i < pos1; ++i) s1 += s[i];
    for (int i = pos1 + 1; i < n; ++i) s1 += s[i];
    for (int i = 0; i < pos2; ++i) s2 += s[i];
    for (int i = pos2 + 1; i < n; ++i) s2 += s[i];
    s2 += ')';
    if (ok(s1) || ok(s2)) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}