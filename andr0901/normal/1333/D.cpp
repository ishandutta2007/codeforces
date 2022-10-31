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
    int initial_k = k;
    string a;
    cin >> a;
    vector <vector <int>> ans(n * n);

    vector <vector <int>> REAL_ANS;
    int pos = 0;
    for (int i = 0; ; ++i) {
        forn (j, 0, n - 1)
            if (a[j] == 'R' && a[j + 1] == 'L')
                ans[i].pb(j);
        for (int j : ans[i])
            swap(a[j], a[j + 1]);
        if (sz(ans[i]) == 0) {
            if (k < 0)
                return cout << -1, 0;
            forn (j, 0, i) {
                vector <int> cur;
                forn (l, 0, sz(ans[j])) {
                    int t = ans[j][l];
                    if (k == 0)
                        cur.pb(t);
                    else {
                        REAL_ANS.pb({t});
                        //cout << "1 " << t + 1 << "\n";
                        if (l != sz(ans[j]) - 1)
                            --k;
                    }
                }
                if (!cur.empty()) {
                    REAL_ANS.pb(cur);
                    pos++;
                }
                //cout << k << "\n";
            }
            break;
        }
        --k;
        //cout << a << "\n";
    }
    if (sz(REAL_ANS) < initial_k)
        return cout << -1, 0;
    for (auto& i : REAL_ANS) {
        cout << sz(i) << " ";
        for (int j : i)
            cout << j + 1 << " ";
        cout << "\n";
    }
    return 0;
}