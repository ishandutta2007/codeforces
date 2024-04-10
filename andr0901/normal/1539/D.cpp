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

#define int long long

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    multiset<pii> items;
    forn (i, 0, n) {
        int cnt, sale;
        cin >> cnt >> sale;
        items.emplace(sale, cnt);
    }
    int bought = 0;
    int ans = 0;
    while (!items.empty()) {
        int mn = items.begin()->first;
        if (bought >= mn) {
            bought += items.begin()->second;
            ans += items.begin()->second;
            items.erase(items.begin());
        } else {
            int diff = mn - bought;
            if (items.rbegin()->second <= diff) {
                bought += items.rbegin()->second;
                ans += 2 * items.rbegin()->second;
                items.erase(--items.end());
            } else {
                ans += 2 * diff;
                bought += diff;
                auto t = *items.rbegin();
                t.second -= diff;
                items.erase(--items.end());
                items.insert(t);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}