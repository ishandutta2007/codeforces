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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    cin >> a;
    vector <int> b;
    for (int x : a)
        b.pb(x);
    sort(all(b)), b.erase(unique(all(b)), b.end());
    if (sz(b) > k) {
        cout << "-1\n";
        return;
    }
    int j = 0;
    while (sz(b) < k) {
        b.pb(b[j]);
        ++j;
    }
    vector <int> ans;
    int s = 0;
    j = 0;
    forn (i, 0, k) {
        int x = b[j];
        j = (j + 1) % sz(b); 
        ans.pb(x);
        s += x;
    }
    int i = 0;
    while (i < n) {
        if (a[i] == b[j]) {
            ans.pb(a[i]);
            ++i;
        } else {
            ans.pb(b[j]);
        }
        j = (j + 1) % sz(b);
    }
    cout << sz(ans) << "\n" << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}