#pragma GCC optmize("Ofast")
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

bool good(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size())
        return cout << "No", 0;
    forn (i, 0, s.size())
        if (good(s[i]) && !good(t[i]) || !good(s[i]) && good(t[i]))
            return cout << "No", 0;
    cout << "Yes";
    return 0;
}