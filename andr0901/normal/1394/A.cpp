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

#define int long long

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    vector <int> a(n);
    cin >> a;
    sort(all(a));
    if (a.back() <= m) {
        ll sum = 0;
        forn (i, 0, n)
            sum += a[i];
        cout << sum;
        return 0;
    }
    long long sum_muting = 0, sum_all = 0;
    int cnt_muting = 0;
    forn (i, 0, n) {
        if (a[i] > m) {
            ++cnt_muting;
            sum_muting += a[i];
        }
        sum_all += a[i];
    }
    cerr << sum_all << " " << sum_muting << "\n";
    vector <long long> pr(n + 1);
    forn (i, 0, n)
        pr[i + 1] = pr[i] + a[i];
    long long ans = 0, sum = 0;
    forn (i, 0, cnt_muting + 1) {
        cerr << "\n" << i << ":\n";
        long long banned_days = 1LL * (i - 1) * d;
        cerr << banned_days << " ";
        if (cnt_muting - i > banned_days) {
            if (cnt_muting - i - banned_days > d) {
                if (i != n)
                    sum += a[n - i - 1];
                continue;
            }
            banned_days += cnt_muting - i - banned_days;
        }
        int j = banned_days - (cnt_muting - i);
        cerr << j << " ";
        if (j != 0 && (j - 1 >= n || a[j - 1] > m)) {
            if (i != n)
                sum += a[n - i - 1];
            continue;
        }
        if (i)
            chkmax(ans, sum_all - 
                    (pr[j] + (sum_muting - sum)));
        cerr << sum_all - 
                    (pr[j] + (sum_muting - sum)) << " ";
        if (i != n)
            sum += a[n - i - 1];
    }
    cerr << "\n";
    cout << ans;
    return 0;
}