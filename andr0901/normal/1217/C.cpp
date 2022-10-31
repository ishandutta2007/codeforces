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

string s;

int get(int l, int r) {
    int ans = 0, pow = 1;
    for (int i = r - 1; i >= l; i--) {
        if (s[i] == '1') 
            ans += pow;
        pow *= 2;
    }
    return ans;
}

void solve() {
    cin >> s;
    int n = sz(s), cur = 0;
    vector <int> zeroes(n);
    forn (i, 0, n) {
        if (s[i] == '1') {
            zeroes[i] = cur;
            cur = 0;
        }
        else 
            cur++;
    }
    ll ans = 0;
    forn (i, 0, n) {
        if (s[i] == '0') 
            continue;
        forn (j, i + 1, min(n + 1, i + 30)) {
            int t = get(i, j), len = j - i;
            //cout << i << " " << j << "  " << get(i, j) << "\n";
            if (len <= t && t <= len + zeroes[i]) 
                ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}