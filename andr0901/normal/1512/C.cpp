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

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = a + b;
    forn (i, 0, n)
        if (s[i] == '0')
            --a;
        else if (s[i] == '1')
            --b;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (s[i] != '?' && s[j] == '?') {
            if (s[i] == '1') {
                s[j] = '1';
                --b;
            } else {
                s[j] = '0';
                --a;
            }
        } else if (s[i] == '?' && s[j] != '?') {
            if (s[j] == '1') {
                s[i] = '1';
                --b;
            } else {
                s[i] = '0';
                --a;
            }
        } else if (s[i] != '?' && s[j] != '?') {
            if (s[i] != s[j]) {
                cout << "-1\n";
                return;
            }
        }
    }
    cerr << s << "\n";
    if (a < 0 || b < 0) {
        cout << "-1\n";
        return;
    }
    if (a % 2 && b % 2) {
        cout << "-1\n";
        return;
    }
    if (a % 2) {
        if (s[n / 2] != '?') {
            cout << "-1\n";
            return;
        }
        s[n / 2] = '0';
        --a;
    }
    if (b % 2) {
        if (s[n / 2] != '?') {
            cout << "-1\n";
            return;
        }
        s[n / 2] = '1';
        --b;
    }
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (s[i] == '?' && s[j] == '?') {
            if (a) {
                s[i] = s[j] = '0';
                a -= 2;
            } else {
                s[i] = s[j] = '1';
                b -= 2;
            }
        }
    }
    cout << (a == 0 && b == 0 ? s : "-1") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}