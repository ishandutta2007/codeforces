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
    string s;
    cin >> s;
    int x;
    cin >> x;
    int n = s.size();
    auto check = [&](int i) {
        return 0 <= i && i < n;
    };
    vector <bool> is_zero(n);
    forn (i, 0, n) {
        if (s[i] == '0') {
            if (check(i - x))
                is_zero[i - x] = true;
            if (check(i + x))
                is_zero[i + x] = true;
        }
    }
    string w(n, 0);
    forn (i, 0, n)
        w[i] = (is_zero[i] ? '0' : '1');
    string real_s(n, '0');
    forn (i, 0, n) {
        if (w[i] == '1') {
            if (check(i - x))
                real_s[i - x] = '1';
            if (check(i + x))
                real_s[i + x] = '1';
        }
    }
    cerr << w << " " << real_s << "\n";
    cout << (s == real_s ? w : "-1") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
   int t;
    cin >> t;
    while (t --> 0)
        solve(); 
    return 0;
}