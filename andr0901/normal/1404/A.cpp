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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> a(k, -1);
    forn (i, 0, n) {
        int &cur = a[i % k];
        if (s[i] == '0') {
            if (cur == -1)
                cur = 0;
            else if (cur == 1) {
                cout << "NO\n";
                return;
            }
        } else if (s[i] == '1') {
            if (cur == -1)
                cur = 1;
            else if (cur == 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cerr << a << "\n";
    vector <int> cnt(2);
    forn (i, 0, k)
        if (a[i] != -1)
            cnt[a[i]]++;
    sort(all(cnt));
    cout << (cnt[1] > k / 2 ? "NO" : "YES") << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}