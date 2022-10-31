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

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> cnt_l(n), cnt_r(n);
    forn (i, 0, l) {
        int x;
        cin >> x;
        cnt_l[x - 1]++;
    }
    forn (i, 0, r) {
        int x;
        cin >> x;
        cnt_r[x - 1]++;
    }
    forn (i, 0, n) {
        int mn = min(cnt_l[i], cnt_r[i]);
        cnt_l[i] -= mn;
        cnt_r[i] -= mn;
    }
    int sum_l = accumulate(all(cnt_l), 0);
    int sum_r = accumulate(all(cnt_r), 0);
    if (sum_l > sum_r) {
        swap(cnt_l, cnt_r);
        swap(sum_l, sum_r);
    }
    int need_change = (sum_r - sum_l); 
    int ans = 0;
    forn (i, 0, n) {
        int can_change = cnt_r[i] / 2 * 2;
        int to_change = min(can_change, need_change);
        cerr << i << " " << can_change << " " << to_change << " " << need_change << " " << ans << "\n"; 
        ans += to_change / 2;
        need_change -= to_change;
    }
    cerr << "\n";
    cout << ans + sum_l + need_change << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}