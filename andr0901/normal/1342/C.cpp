#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define int long long

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

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

void solve() {
    int a, b, q;
    cin >> a >> b >> q;
    int n = a * b / gcd(a, b);
    vector <int> good(n);
    long long s = 0;
    vector <int> pr(n + 1);
    forn (i, 0, n) {
        if ((i % a) % b != (i % b) % a)
            good[i] = 1;
        pr[i + 1] = pr[i] + good[i];
        s += good[i];
    }
    //cout << pr << ":\n";
    while (q --> 0) {
        long long l, r;
        cin >> l >> r;
        long long ans = 0;
        long long down = (l + n - 1) / n, up  = r / n;
        ans += 1LL * (up - down) * s;
        down *= n;
        l %= n;
        if (l == 0)
            l += n;
        ans += pr[n] - pr[l];
        /*forn (i, l, down)
            ans += good[i % n];*/
        up *= n;
        ans += pr[r % n + 1];
        /*forn (i, up, r + 1)
            ans += good[i % n];*/
        cout << ans << " ";
    }
    cout << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}