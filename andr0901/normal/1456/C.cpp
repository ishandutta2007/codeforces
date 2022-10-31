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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    cin >> a;
    sort(all(a));
    ++k;
    vector <int> pr(n);
    forn (i, 0, n)
        pr[i] = (i == 0 ? 0 : pr[i - 1] + (i / k) * a[i]);
    cerr << pr << "\n";
    int ans = pr[n - 1];
    int suf = 0, sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        cerr << i << ": " << suf << " " << sum << " " << pr[i] << "\n";
        chkmax(ans, pr[i] + sum);
        if (i % k != 0) {
            sum += suf;
        }
        sum += ((i - 1) / k + 1) * a[i];
        suf += a[i];
    }
    cout << ans;
    return 0;
}