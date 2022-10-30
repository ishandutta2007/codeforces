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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<long long> s(2);
    forn (i, 0, n)
        s[i % 2] += a[i];
    auto check_neighbours = [&](int i) {
        int neighbours = 0;
        if (i - 1 >= 0)
            neighbours += a[i - 1];
        if (i + 1 < n)
            neighbours += a[i + 1];
        return a[i] <= neighbours;
    };
    vector<bool> is_good(n);
    int sum_good = 0;
    forn (i, 0, n) {
        is_good[i] = check_neighbours(i);
        sum_good += is_good[i];
    }
    if (s[0] == s[1] && sum_good == n) {
        cout << "YES\n";
        return;
    }
    cerr << s << "\n";
    for (int i = 0, j = 1; j < n; ++i, ++j) {
        int cur_good = sum_good;
        if (i - 1 >= 0)
            cur_good -= is_good[i - 1];
        cur_good -= is_good[i];
        cur_good -= is_good[j];
        if (j + 1 < n)
            cur_good -= is_good[j + 1];
        vector<long long> cur_s = s;
        cur_s[i % 2] -= a[i];
        cur_s[j % 2] -= a[j];
        
        swap(a[i], a[j]);

        cur_s[i % 2] += a[i];
        cur_s[j % 2] += a[j];
        if (i - 1 >= 0)
            cur_good += check_neighbours(i - 1);
        cur_good += check_neighbours(i);
        cur_good += check_neighbours(j);
        if (j + 1 < n)
            cur_good += check_neighbours(j + 1);
        cerr << i << ": " << cur_good << " " << cur_s << "\n";;

        if (cur_s[0] == cur_s[1] && cur_good == n) {
            cerr << i << "\n";
            cout << "YES\n";
            return;
        }

        swap(a[i], a[j]);
    }
    cout << "NO\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        solve();
        cerr << "\n";
    }
    return 0;
}