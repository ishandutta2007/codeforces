#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

string s;

bool tw(int x) {
    fr(i, 26)
        frab(j, i + 1, 26)
            if (s[x + i] == s[x + j] && s[x + i] != '?')
                return false;
    return true;
}

string mak(int x) {
    string t = s;
    fr(i, 26)
        if (t[x + i] == '?') {
            frab(ch, 'A', 'Z' + 1) {
                bool fnd = false;
                frab(j, x, x + 26)
                    if (t[j] == ch)
                        fnd = true;
                if (!fnd) {
                    t[x + i] = ch;
                    break;
                }
            }
        }
    fr(i, t.size())
        if (t[i] == '?')
            t[i] = 'A';
    return t;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s;
    fr(i, (int)s.size() - 25) {
        if (tw(i)) {
            cout << mak(i);
            return 0;
        }
    }
    cout << -1;
}