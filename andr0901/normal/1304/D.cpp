#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cur = 1;
    vector <int> ans(n);
    for (int i = n - 2; i >= 0; --i) {
        if ((!i || (s[i - 1] == '>')) && s[i] == '<') {
            int j = i;
            while (j < n - 1 && s[j] == '<')
                ans[j++] = cur++;
            if (j == n - 1 && s[j - 1] == '<')
                ans[j] = cur++;
        }
    }
    cur = n;
    forn (i, 0, n)
        if (!ans[i])
            ans[i] = cur--;
    for (int i : ans)
        cout << i << " ";
    cout << "\n";

    cur = 1;
    ans = vector <int> (n);
    forn (i, 0, n - 1)
        if (s[i] == '<')
            ans[i] = cur++;
    if (s[n - 2] == '<')
        ans[n - 1] = cur++;
    cur = n;
    forn (i, 0, n)
        if (!ans[i])
            ans[i] = cur--;
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}