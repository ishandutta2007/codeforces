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
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <pii> ans;
    set <pii> ones;
    set <pii> twos;
    int lst = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0)
            continue;
        if (a[i] == 1) {
            ans.eb(i + 1, lst);
            ones.emplace(i + 1, lst);
            ++lst;
        }
        if (a[i] == 2) {
            if (ones.empty()) {
                cout << "-1\n";
                return 0;
            }
            auto [x, y] = *ones.begin();
            ones.erase(ones.begin());
            ans.eb(i + 1, y);
            twos.emplace(i + 1, y);
        }
        if (a[i] == 3) {
            if (ones.empty() && twos.empty()) {
                cout << "-1\n";
                return 0;
            }
            int x, y;
            if (!twos.empty()) {
                tie(x, y) = *twos.begin();
                twos.erase(twos.begin());
            } else {
                tie(x, y) = *ones.begin();
                ones.erase(ones.begin());
            }
            twos.emplace(i + 1, lst);
            ans.eb(i + 1, lst);
            ans.eb(x, lst);
            ++lst;
        }
    }
    cout << ans.size() << "\n";
    for (auto [x, y] : ans)
        cout <<n - y + 1 << " " << x << "\n";
    return 0;
}