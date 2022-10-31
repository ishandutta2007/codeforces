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

int solve(vector<int>& a, vector<int>& b) {
    int suf = 0;
    forn (i, 0, sz(b)) {
        auto j = lower_bound(all(a), b[i]);
        if (j != a.end() && *j == b[i])
            ++suf;
    }
    int ans = 0;
    forn (i, 0, sz(b)) {
        {
            auto j = lower_bound(all(a), b[i]);
            if (j != a.end() && *j == b[i])
                --suf;
        }
        auto j = upper_bound(all(a), b[i]);
        if (j == a.begin()) {
            continue;
        }
        int k = --j - a.begin();
        chkmax(ans, suf + lower_bound(all(b), b[i] + 1) - lower_bound(all(b), b[i] - k));
    }
    cerr << ans << " ";
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    cin >> a >> b;
    vector<int> neg_a, pos_a, neg_b, pos_b;
    for (int x : a) {
        if (x < 0)
            neg_a.pb(-x);
        else
            pos_a.pb(x);
    }
    for (int x : b) {
        if (x < 0)
            neg_b.pb(-x);
        else
            pos_b.pb(x);
    }
    reverse(all(neg_a));
    reverse(all(neg_b));
    cout << solve(neg_a, neg_b) + solve(pos_a, pos_b) << "\n";
    cerr << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;   
}