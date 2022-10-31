#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

bool check(string &s) {
    int x, y, z;
    x = y = z = -1;
    forn (i, 0, s.size()) {
        if ('a' <= s[i] && s[i] <= 'z')
            x = i;
        if ('A' <= s[i] && s[i] <= 'Z')
            y = i;
        if ('0' <= s[i] && s[i] <= '9')
            z = i;
    }
    return x != -1 && y != -1 && z != -1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        string s;
        cin >> s;
        int x, y, z;
        x = y = z = -1;
        forn (i, 0, s.size()) {
            if ('a' <= s[i] && s[i] <= 'z')
                x = i;
            if ('A' <= s[i] && s[i] <= 'Z')
                y = i;
            if ('0' <= s[i] && s[i] <= '9')
                z = i;
        }
        if (check(s)) {
            cout << s << "\n";
            continue;
        }
        bool f = 1;
        string t = s;
        forn (i, 0, s.size()) {
            t[i] = 'a';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = 'A';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = '1';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = s[i];
        }
        if (!f)
            continue;
        forn (i, 0, s.size() - 1) {
            t[i] = 'a', t[i + 1] = 'A';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = 'a', t[i + 1] = '1';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = '1', t[i + 1] = 'a';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = '1', t[i + 1] = 'A';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = 'a', t[i + 1] = 'A';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = 'a', t[i + 1] = '1';
            if (check(t)) {
                cout << t << "\n";
                f = 0;
                break;
            }
            t[i] = s[i], t[i + 1] = s[i + 1];
        }
        if (!f)
            continue;
        cout << "Aa1";
        forn (i, 3, s.size())
            cout << s[i];
        cout << '\n';
    }
    return 0;
}