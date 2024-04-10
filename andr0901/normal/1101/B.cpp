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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int i = 0;
    for (; i < s.size(); i++)
        if (s[i] == '[')
            break;
    if (i == s.size())
        return cout << -1, 0;
    i++;
    for (; i < s.size(); i++)
        if (s[i] == ':')
            break;
    if (i == s.size())
        return cout << -1, 0;
    int j = (int)s.size() - 1;
    for (; j >= 0; j--)
        if (s[j] == ']')
            break;
    if (j == -1)
        return cout << -1, 0;
    j--;
    for (; j >= 0; j--)
        if (s[j] == ':')
            break;
    if (j == -1)
        return cout << -1, 0;
    if (i >= j)
        return cout << -1, 0;
    int ans = 0;
    for (int k = i; k <= j; k++)
        if (s[k] == '|')
            ans++;
    cout << ans + 4;
    return 0;
}