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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    bool a, b;
    a = b = 0;
    forn (i, 0, s.size()) {
        if (s[i] == '1') {
            if (!a)
                cout << "1 3\n";
            else
                cout << "1 1\n";
            a ^= 1;
        } else {
            if (!b)
                cout << "3 1\n";
            else
                cout << "1 1\n";
            b ^= 1;
        }
    }
    return 0;
}