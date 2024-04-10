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
    int n, k;
    cin >> n >> k;
    vector <string> a(n);
    cin >> a;
    reverse(all(a));
    vector <string> digits = {"1110111", // 0
                              "0010010", // 1 
                              "1011101", // 2
                              "1011011", // 3
                              "0111010", // 4
                              "1101011", // 5
                              "1101111", // 6
                              "1010010", // 7
                              "1111111", // 8
                              "1111011"};// 9
    auto diff = [&](string& x, string& y) -> int {
        int ans = 0;
        forn (i, 0, 7) {
            if (x[i] > y[i])
                return 10000;
            ans += y[i] - x[i];
        }
        return ans;
    };
    vector <vector <int>> dp(n + 1, vector <int> (k + 1, -1));
    dp[0][0] = 0;
    forn (i, 0, n) {
        forn (j, 0, k + 1) {
            if (dp[i][j] == -1)
                continue;
            forn (l, 0, 10) {
                int new_j = j + diff(a[i], digits[l]);
                //cout <<  i << " " << j << " " << l << ": " << new_j << "\n";
                if (new_j < k + 1 && l > dp[i + 1][new_j])
                    dp[i + 1][new_j] = l;
            }
            //cout << "\n";
        }
        //cout << dp[i + 1] << "\n";
    }
    /*forn (i, 0, n + 1)
        cout << dp[i] << "\n";*/
    if (dp[n][k] == -1)
        cout << dp[n][k];
    else {
        vector <int> ans;
        int j = k;
        for (int i = n - 1; i >= 0; --i) {
            cout << dp[i + 1][j];
            j -= diff(a[i], digits[dp[i + 1][j]]);
        }
    }
    return 0;
}