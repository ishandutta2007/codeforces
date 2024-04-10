//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

#define int long long

const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <int> pos, neg;
    bool zero = false;
    forn (i, 0, n) {
        if (a[i] > 0)
            pos.pb(a[i]);
        if (a[i] == 0)
            zero = true;
        if (a[i] < 0)
            neg.pb(a[i]);
    }
    sort(rall(pos)), sort(all(neg));
    int ans = -INF;
    if (zero)
        ans = 0;
    if (pos.empty()) {
        if (sz(neg) < 5) {
            cout << 0;
        } else {
            reverse(all(neg));
            int cur = 1;
            forn (i, 0, 5)
                cur *= neg[i];
            chkmax(ans, cur);
            cout << ans;
        }
        cout << "\n";
        return;
    } else {
        for (int cnt = 0; cnt < 5; cnt += 2) {
            int cur = 1;
            if (sz(pos) < 5 - cnt)
                continue;
            forn (i, 0, 5 - cnt)
                cur *= pos[i];
            if (sz(neg) < cnt)
                continue;
            forn (i, 0, cnt)
                cur *= neg[i];
            cerr << cur << " ";
            chkmax(ans, cur);
        }
    }
    reverse(all(pos)), reverse(all(neg));
    for (int cnt = 1; cnt <= 5; cnt += 2) {
        int cur = 1;
        if (sz(pos) < 5 - cnt)
            continue;
        forn (i, 0, 5 - cnt)
            cur *= pos[i];
        if (sz(neg) < cnt)
            continue;
        forn (i, 0, cnt)
            cur *= neg[i];
        cerr << cur << " ";
        chkmax(ans, cur);
    }
    cout << ans << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}