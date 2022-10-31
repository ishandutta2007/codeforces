#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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
    int t;
    cin >> t;
    while (t --> 0) {
        string s;
        cin >> s;
        vector <char> odd, even;
        for (char c : s) {
            if (c % 2)
                odd.pb(c);
            else
                even.pb(c);
        }
        reverse(all(odd)), reverse(all(even));
        vector <char> ans;
        while (!odd.empty() && !even.empty()) {
            if (odd.back() < even.back()) {
                ans.pb(odd.back());
                odd.pop_back();
            } else {
                ans.pb(even.back());
                even.pop_back();
            }
        }
        while (!odd.empty()) {
            ans.pb(odd.back());
            odd.pop_back();
        }
        while (!even.empty()) {
            ans.pb(even.back());
            even.pop_back();
        }
        for (char c : ans)
            cout << c;
        cout << "\n";
    }
    return 0;
}