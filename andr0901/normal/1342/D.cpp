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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    multiset <int> a;
    forn (i, 0, n) {
        int t;
        cin >> t;
        a.insert(-t);
    }
    vector <int> b(k + 2);
    b[0] = -1e9;
    forn (i, 1, k + 1) {
        cin >> b[i];
        b[i] *= -1;
    }
    vector <vector <int>> ans;
    while (!a.empty()) {
        int lst_b = sz(b);
        vector <int> cur;
        int prev = -1e9;
        while (true) {
            int cur_b = (int)(upper_bound(all(b), -(sz(cur) + 1)) - b.begin()) - 1;
            //cout << cur_b << ": ";
            auto j = a.lower_bound(-cur_b);
            if (j == a.end())
                break;
            if (cur_b <= 0)
                break;
            int nxt = min(cur_b, *j);
            cur.pb(nxt);

            prev = nxt;
            a.erase(j);
            lst_b = nxt;
            //cout << prev << " " << lst_b << "\n";
        }
        /*for (auto i = a.begin(); i != a.end();) {
            if (sz(cur) + 1 <= b[-(*i)]) {
                auto j = i;
                cur.pb(*i);
                ++i;
                a.erase(j);
            } else {
                ++i;
            }
        }*/
        ans.pb(cur);
    }
    cout << sz(ans) << "\n";
    for (auto& i : ans) {
        cout << sz(i) << " ";
        for (auto j : i)
            cout << -j << " ";
        cout << "\n";
    }
    return 0;
}