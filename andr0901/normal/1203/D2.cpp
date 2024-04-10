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

string s, t;

vector <int> get() {
    vector <int> ans(sz(t) + 1);
    int j = 0;
    forn (i, 0, sz(s)) {
        if (j < sz(t) && s[i] == t[j]) {
            ans[j + 1] = i + 1;
            j++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s >> t;
    vector <int> a = get();
    reverse(all(s)), reverse(all(t));
    vector <int> b = get();
    reverse(all(b));
    forn (i, 0, sz(t) + 1) 
        b[i] = sz(s) - b[i];
    int ans = 0;
    forn (i, 0, sz(t) + 1) {
        //cout << a[i] << " " << b[i] << "\n";
        ans = max(ans, b[i] - a[i]);
    }
    cout << ans;
    return 0;
}