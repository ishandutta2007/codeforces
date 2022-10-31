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
    int n, k, z;
    cin >> n >> k >> z;
    vector <int> a(n);
    cin >> a;
    vector <int> pref(n + 1);
    forn (i, 0, n)
        pref[i + 1] = pref[i] + a[i];
    auto get = [&](int l, int r) {
        return pref[r] - pref[l];
    };
    long long sum = 0, ans = 0;
    for (int i = 0; i < n && k >= 0; ++i, --k) {
        sum += a[i];
        if (!i) {
            continue;
        }
        forn (j, 1, z + 1) {
            int t = j + (j - 1), k_left = k - t;
            if (k_left < 0)
                continue;
            long long cur = sum + (j - 1) * a[i] + j * a[i - 1];
            chkmax(ans, cur + get(i, i + k_left)); 
        }
       /* int t = z + z - 1, steps_left = z, k_left = k - t;
        while (steps_left && k_left < 0) {
            steps_left--;
            t -= 2;
            k_left += 2;
        }
        if (k_left < 0 || t < 0)
            continue;*/
        //cerr << i << " " << sum << " " << k_left << " " << cur + get(i - 1, i - 1 + k_left) << "\n";;    
    }
    if (k < 0)
        chkmax(ans, sum);
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