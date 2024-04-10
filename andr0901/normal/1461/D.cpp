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

vector <int> a;
vector <long long> pr;

long long get(int l, int r) {
    return pr[r + 1] - pr[l];
}

set <long long> used;

void solve(int l, int r) {
    cerr << l << " " << r << "\n";
    used.insert(get(l, r));
    if (a[l] == a[r]) {
        return;
    }
    int m = (a[l] + a[r]) / 2;
    int mid_idx = upper_bound(all(a), m) - a.begin() - 1;
    solve(l, mid_idx), solve(mid_idx + 1, r); 
}

void solve() {
    int n, q;
    cin >> n >> q;
    a = vector <int> (n);
    cin >> a;
    sort(all(a));
    pr = vector <long long> (n + 1);
    forn (i, 0, n)
        pr[i + 1] = pr[i] + a[i];
    used.clear();
    solve(0, n - 1);
    while (q --> 0) {
        int t;
        cin >> t;
        cout << (used.find(t) == used.end() ? "No" : "Yes") << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}