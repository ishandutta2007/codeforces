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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n = 3, m = 4;
    int k;
    cin >> k;
    int mx = 0;
    forn (i, 0, 30)
        if ((k >> i) & 1)
            mx = i;
    vector <vector <int>> a(3);
    a[0] = {k | (1 << (mx + 1)), k, k, 0};
    a[1] = {1 << (mx + 1), 1 << (mx + 2), k, 0};
    a[2] = {k | (1 << (mx + 1)), k | (1 << (mx + 1)), k | (1 << (mx + 1)), k};

    vector <vector <int>> dp(n + 1, vector <int> (m + 1));
    dp[0][1] = a[0][0];
    forn (i, 1, n + 1)
        forn (j, 1, m + 1)
            dp[i][j] = max(dp[i - 1][j] & a[i - 1][j - 1], dp[i][j - 1] & a[i - 1][j - 1]);
    cout << "3 4\n";
    forn (i, 0, n)
        cout << a[i] << "\n";
    /*cout << "\n";
    forn (i, 0, n + 1)
        cout << dp[i] << "\n";*/
    return 0;
}