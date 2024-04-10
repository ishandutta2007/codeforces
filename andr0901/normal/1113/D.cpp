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

bool check(string s) {
    forn (i, 0, s.size())
        if (s[i] != s[s.size() - i - 1])
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int ans = 3;
    forn (i, 1, n - 1) {
        string s2;
        forn (j, i, n)
            s2 += s[j];
        forn (j, 0, i)
            s2 += s[j];
        if (s2 != s && check(s2))
            return cout << 1, 0;
    }
    forn (i, 1, n / 2)
        if (s[0] != s[i])
            return cout << 2, 0;
    cout << "Impossible";
    return 0;
}