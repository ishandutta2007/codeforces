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
    int sum;
    cin >> s >> sum;
    int cur = 0;
    s = '0' + s;
    vector <int> good;
    forn (i, 0, sz(s)) {
        cur += (s[i] - '0');
        if (s[i] != '9' && cur + 1 <= sum) {
            good.pb(i);
        }
    }
    if (cur <= sum) {
        cout << 0 << "\n";
        return;
    }
    string init_s = s;
    int idx = good.back();
    s[idx]++;
    forn (i, idx + 1, sz(s))
        s[i] = '0';
    cerr << s << ": ";
    cout << stoll(s) - stoll(init_s) << "\n";  
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();   
    return 0;
}