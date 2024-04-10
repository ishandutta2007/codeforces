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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string a, b;
    bool alternate = false;
    a.resize(n), b.resize(n);
    forn (i, 0, n) {
        if (alternate) {
            a[i] = '0', b[i] = s[i];
            continue;
        }
        if (s[i] == '0')
            a[i] = b[i] = '0';
        if (s[i] == '1') {
            alternate = true;
            a[i] = '1';
            b[i] = '0';
        }
        if (s[i] == '2') {
            a[i] = b[i] = '1';
        }
    }
    cout << a << "\n" << b << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}