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

string s;
vector <vector <int>> dp;

bool is_palindrome(int l, int r) {
    if (dp[l][r] != -1)
        return dp[l][r];
    if (r - l <= 0)
        return dp[l][r] = true;
    if (s[l] != s[r])
        return dp[l][r] = false;
    else
        return dp[l][r] = is_palindrome(l + 1, r - 1);
}

void solve() {
    cin >> s;
    int n = sz(s);
    string ans = "";
    dp = vector <vector <int>> (n, vector <int> (n, -1));
    for (int i = 0, j = n - 1; i < n / 2; ++i, --j) {
        if (s[i] != s[j]) {
            --i, ++j;
            for (int k = j - 1; k > i; --k) {
                if (is_palindrome(k, j - 1)) {
                    if (i + 1 + n - j + j - k > sz(ans)) {
                        ans = s.substr(0, i + 1) + s.substr(k, n - k);
                    }
                }
            }
            break;
        }
    }

    reverse(all(s));
    dp = vector <vector <int>> (n, vector <int> (n, -1));
    for (int i = 0, j = n - 1; i < n / 2; ++i, --j) {
        if (s[i] != s[j]) {
            --i, ++j;
            for (int k = j - 1; k > i; --k) {
                if (is_palindrome(k, j - 1)) {
                    if (i + 1 + n - j + j - k > sz(ans)) {
                        ans = s.substr(0, i + 1) + s.substr(k, n - k);
                    }
                }
            }
            break;
        }
    }

    if (sz(ans) == 0)
        ans = s;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}