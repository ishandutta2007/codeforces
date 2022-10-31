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
    int n;
    cin >> n;
    vector <int> a(n);
    ll ans_pos = 0, ans_neg = 0;
    int cnt_pos = 1, cnt_neg = 0;
    vector <int> pref(n + 1, 1);
    forn (i, 0, n) {
        cin >> a[i];
        if (a[i] > 0)
            a[i] = 1;
        if (a[i] < 0)
            a[i] = -1;
        pref[i + 1] = pref[i] * a[i];
        if (pref[i + 1] == 1) {
            ans_pos += cnt_pos;
            ans_neg += cnt_neg;
        } else {
            ans_pos += cnt_neg;
            ans_neg += cnt_pos;
        }
        if (pref[i + 1] > 0)
            cnt_pos += 1;
        else
            cnt_neg += 1;
        //cout << ans_pos << " " << ans_neg << "  " << cnt_pos << " " << cnt_neg << "\n";
    }
    cout << ans_neg << " " << ans_pos;
    return 0;
}