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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

const int N = 1e7 + 5;

vector <int> sieve() {
    vector <int> lp(N), p;
    forn (i, 2, N) {
        if (!lp[i]) {
            lp[i] = i;
            p.pb(i);
        }
        for (int j = 0; j < sz(p) && p[j] < lp[i] && i * p[j] <= N; ++j)
            lp[i * p[j]] = p[j];
    }
    return lp;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <vector <int>> ans(2, vector <int> (n, -1));
    auto lp = sieve();
    forn (i, 0, n) {
        int j = lp[a[i]];
        if (!j)
            continue;
        while (a[i] % j == 0)
            a[i] /= j;
        if (a[i] > 1) {
            ans[0][i] = j;
            ans[1][i] = a[i];
       }
    }
    cout << ans[0] << "\n" << ans[1];
    return 0;
}