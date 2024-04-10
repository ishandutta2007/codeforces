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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    deque <char> ans;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s.size() % 2) {
            ans.pb(s[i]);
            ans.pb(s[j]);
        } else {
        ans.pb(s[j]);
        ans.pb(s[i]);
        }
    }
    if (s.size() % 2)
        ans.pb(s[s.size() / 2]);
    reverse(ans.begin(), ans.end());
    forn (i, 0, ans.size())
        cout << ans[i];
    return 0;
}