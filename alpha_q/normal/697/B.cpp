#include <bits/stdc++.h>

using namespace std;

int _stoi (string x) {
    int r = 0;
    for (int i = 0; i < x.size(); ++i) {
        r *= 10;
        r += x[i] - '0';
    }
    return r;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s; cin >> s;
    int i = 0, n = s.size();

    string a = "", d = "", s_b = "";
    while (s[i] != '.') a += s[i++];
    i++;
    while (s[i] != 'e') d += s[i++];
    i++;
    while (i < n) s_b += s[i++];
    int b = _stoi(s_b);

    string z = a + d;
    int l = z.size(), pos = b + 1, start = 0;
    string ans = "";
    bool flag = 1;

    if (pos < l) {
        for (int i = 0; i < pos; ++i) ans += z[i];
        ans += ".";
        for (int i = pos; i < l; ++i) ans += z[i];
    } else if (pos == l) {
        flag = 0;
        ans += z;
    } else {
        flag = 0;
        ans += z;
        for (int i = l; i < pos; ++i) ans += "0";
    }

    if (ans.size() >= 2 and ans[1] != '.') {
        while (ans[0] == '0') ans.erase(ans.begin());
    }

    l = ans.size();
    if (flag) while (ans[l - 1] == '0') ans.erase(ans.end() - 1), l--;
    if (ans[l - 1] == '.') ans.erase(ans.end() - 1);

    cout << ans << "\n";
    return 0;
}