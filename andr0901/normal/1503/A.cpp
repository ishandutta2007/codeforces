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

bool balanced(const string& a) {
    int bal = 0;
    for (char c : a) {
        if (c == '(') {
            ++bal;
        } else {
            --bal;
        }
        if (bal < 0) {
            return false;
        }
    }
    return bal == 0;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int different = 0;
    forn (i, 0, n)
        if (s[i] == '0')
            ++different;
    if (different % 2) {
        cout << "NO\n";
        return;
    }
    int open = n / 2 - different / 2;
    int turn = 0;
    vector<string> ans(2);
    forn (i, 0, n) {
        if (s[i] == '1') {
            if (open > 0) {
                ans[0] += '(';
                ans[1] += '(';
                --open;
            } else {
                ans[0] += ')';
                ans[1] += ')';
            }
        } else {
            if (turn) {
                ans[0] += '(';
                ans[1] += ')';
            } else {
                ans[0] += ')';
                ans[1] += '(';
            }
            turn ^= 1;
        }
    }
    cerr << ans[0] << "\n" << ans[1] << "\n\n";
    if (balanced(ans[0]) && balanced(ans[1])) {
        cout << "YES\n" << ans[0] << "\n" << ans[1] << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}