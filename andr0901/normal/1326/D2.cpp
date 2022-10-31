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
template <typename T> ostream& operator<<(ostream& out, vector <T> a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <int> m;
vector <vector <int>> p;

int get(char c) {
    return c - 'a' + 1;
}

void compute_h(const string& t, vector <vector <int>>& h) {
    h.clear();
    h.resize(sz(t) + 1, vector <int> (3));
    forn (i, 1, sz(t) + 1)
        forn (j, 0, 3)
            h[i][j] = ((1LL * h[i - 1][j] * p[1][j]) % m[j] + get(t[i - 1])) % m[j];
}

vector <int> get_hash(vector <vector <int>>& h, int l, int r) {
    vector <int> ans(3);
    forn (i, 0, 3)
        ans[i] = (h[r][i] - (1LL * h[l][i] * p[r - l][i]) % m[i] + m[i]) % m[i];
    return ans;
}

vector <vector <int>> h1, h2;

int n;

bool is_palindrome(int l, int r) {
    return get_hash(h1, l, r) == get_hash(h2, n - r, n - l);
}

void solve() {
    string s;
    cin >> s;
    n = sz(s);
    compute_h(s, h1);
    reverse(all(s));
    compute_h(s, h2);
    reverse(all(s));
    string ans = "";
    for (int i = 0, j = n - 1; i < n / 2; ++i, --j) {
        if (s[i] != s[j]) {
            --i, ++j;
            for (int k = i + 1; k < j; ++k) {
                if (is_palindrome(k, j)) {
                    if (i + 1 + n - k > sz(ans))
                        ans = s.substr(0, i + 1) + s.substr(k, n - k);
                    break;
                }
            }
            break;
        }
    }
 
    reverse(all(s));
    compute_h(s, h1);
    reverse(all(s));
    compute_h(s, h2);
    reverse(all(s));    
    for (int i = 0, j = n - 1; i < n / 2; ++i, --j) {
        if (s[i] != s[j]) {
            --i, ++j;
            for (int k = i + 1; k < j; ++k) {
                if (is_palindrome(k, j)) {
                    if (i + 1 + n - k > sz(ans))
                        ans = s.substr(0, i + 1) + s.substr(k, n - k);
                    break;
                }
            }
            break;
        }
    }
 
    if (sz(ans) == 0)
        ans = s;
 
    cout << ans << "\n";
}

const int MAXN = 2e6 + 50;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int INF = 1e9;
    m = {INF + 7, 998244353, INF + 9};
    p.resize(MAXN, vector <int> (3, 1));
    p[1][0] = 37, p[1][1] = 29, p[1][2] = 31;
    forn (i, 2, MAXN)
        forn (j, 0, 3)
            p[i][j] = (1LL * p[i - 1][j] * p[1][j]) % m[j];
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}