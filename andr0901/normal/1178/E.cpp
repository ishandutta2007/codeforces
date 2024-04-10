#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
    vector <int> ans;
    int l = 0, r = sz(s);
    while (r - l > 3) {
        forn (i, l, l + 2) {
            bool to_break = 0;
            forn (j, r - 2, r) {
                if (s[i] == s[j]) {
                    ans.pb(i), ans.pb(j);
                    to_break = 1;
                    break;
                }   
            }
            if (to_break)
                break;
        }
        l += 2, r -= 2;
    }
    if (r - l > 1)
        ans.pb(l);
    sort(all(ans));
    forn (i, 0, sz(ans))
        cout << s[ans[i]];
    return 0;
}