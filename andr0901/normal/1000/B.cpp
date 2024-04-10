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
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 2), on(n + 3), off(n + 3);
    forn (i, 1, n + 1) {
        cin >> a[i];
    }
    a[n + 1] = m;
    for (int i = n + 1; i >= 1; i--) {
        on[i] = on[i + 1];
        off[i] = off[i + 1];
        if (i % 2 == 1)
            on[i] += a[i] - a[i - 1];
        else
            off[i] += a[i] - a[i - 1];
    }  // forn (i, 0, n + 2)
       // cout << on[i] << " " << off[i] << "\n";
    //cout << "\n";
    int cur_on = 0;
    int ans = on[1];
    forn (i, 1, n + 2) {
        if (i % 2 == 1)
            cur_on += a[i] - a[i - 1];
        //cout << cur_on << " " << "  " << off[i + 1] << "    ";
        if (a[i - 1] + 1 < a[i]) {
            if (i % 2 == 1)
                cur_on -= (a[i] - a[i - 1] - 1);
            else
                cur_on += (a[i] - a[i - 1] - 1);
            ans = max(ans, cur_on + off[i + 1]);
            if (i % 2 == 1)
                cur_on += (a[i] - a[i - 1] - 1);
            else
                cur_on -= (a[i] - a[i - 1] - 1);
            if (i % 2 == 1)
                cur_on--;
            else
                cur_on++;
            ans = max(ans, cur_on + off[i + 1]);
            if (i % 2 == 1)
                cur_on++;
            else
                cur_on--;
        }
        //cout << ans << "\n";
    }
    cout << ans;
    return 0;
}