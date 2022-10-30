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
    vector <int> a(n);
    forn (i, 0, n) {
        cin >> a[i];
        a[i] *= -1;
    }
    int ans_g = 0, ans_s = 0, ans_b = 0;
    forn (i, 0, n) {
        int g = --upper_bound(all(a), a[i]) - a.begin();
        if (g + g + 2 >= n)
            continue;
        int s = --upper_bound(all(a), a[g + g + 2]) - a.begin();
        if (s + g + 2 >= n)
            continue;
        /*if (n / 2 - (s + 1) > g + 1) {
            cout << g + 1 << " " << s - g << " " << n / 2 - s - 1 << "\n";
            return;
        }*/
        int b = --lower_bound(all(a), a[n / 2]) - a.begin();
        //int b = --upper_bound(all(a), a[s + g + 2]) - a.begin();
        //cout << i << ": " << g << " " << s << " " << b << "\n";
        
        if (b - s > g + 1 &&  b > ans_g + ans_s + ans_b) {
            ans_g = g + 1;
            ans_s = s - g;
            ans_b = b - s;
            //cout << "upd" << i << "\n";
        }
    }
    cout << ans_g  << " " << ans_s << " " << ans_b << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}