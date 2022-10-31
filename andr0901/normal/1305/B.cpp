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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector <vector <int>> ans;
    vector <bool> used(sz(s));
    while (true) {
        vector <int> open, close;
        forn (i, 0, sz(s)) {
            if (used[i])
                continue;
            if (s[i] == '(')
                open.pb(i);
            else
                close.pb(i);
        }
        reverse(all(close));
        vector <int> cur;
        int j = 0;
        forn (i, 0, sz(open)) {
            if (j >= sz(close))
                break;
            if (open[i] < close[j]) 
                cur.pb(open[i]), cur.pb(close[j]);
            ++j;
        }
        if (cur.empty())
            break;
        sort(all(cur));
        for (int i : cur)
            used[i] = true;
        ans.pb(cur);
    }
    cout << sz(ans) << "\n";
    for (auto& i : ans) {
        cout << sz(i) << "\n";
        for (int j : i)
            cout << j + 1 << " ";
        cout << "\n";
    }
    return 0;
}