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

int l, r;

bool good(int x) {
    return l <= x && x <= r;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m >> l >> r;
    vector <int> a(n);
    cin >> a;
    vector <int> dp(m, -1e9);
    dp[0] = 0;
    forn (i, 0, n) {
        vector <int> new_dp(m, -1e9);
        forn (j, 0, m) {
            if (good((j + a[i] - 1 + m) % m))
                chkmax(new_dp[(j + a[i] - 1 + m) % m], dp[j] + 1);
            else
                chkmax(new_dp[(j + a[i] - 1 + m) % m], dp[j]);

            if (good((j + a[i]) % m))
                chkmax(new_dp[(j + a[i]) % m], dp[j] + 1);
            else
                chkmax(new_dp[(j + a[i]) % m], dp[j]);
        }
        swap(dp, new_dp);
        //cout << dp << "\n";
    }
    cout << *max_element(all(dp));
    return 0;
}