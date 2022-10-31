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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector <pii> ans;
    auto perform = [&](int tp, int i) {
        if (tp == 0) {
            auto t = s.substr(1, i + 1 - 1);
            reverse(all(t));
            s = t + s;
        } else {
            auto t = s.substr(i, sz(s) - 1 - i);
            reverse(all(t));
            s = s + t;
        }
        ans.pb({tp, i});
        cerr << s << "\n";
    };
    perform(1, sz(s) - 2);
    perform(0, sz(s) - 2);
    perform(0, 1);
    cout << ans.size() << "\n";
    for (auto [tp, i] : ans) {
        if (tp == 0)
            cout << 'L';
        else
            cout << 'R';
        cout << " " << i + 1 << "\n";
    }
    return 0;
}