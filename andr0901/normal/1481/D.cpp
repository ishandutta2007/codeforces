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

vector<string> gr;

void solve() {
    int n, m;
    cin >> n >> m;
    gr = vector<string> (n);
    cin >> gr;
    forn (i, 0, n) {
        forn (j, 0, n) {
            if (i == j)
                continue;
            if (gr[i][j] == gr[j][i]) {
                cout << "YES\n";
                forn (k, 0, m + 1)
                    cout << (k % 2 ? i + 1 : j + 1) << " ";
                cout << "\n";
                return;
            }
        }
    }
    if (m % 2) {
        cout << "YES\n";
        forn (i, 0, m + 1)
            cout << (i % 2 ? 1 : 2) << " ";
        cout << "\n";
        return;
    }
    vector<vector<int>> in_a(n), out_a(n), in_b(n), out_b(n);
    forn (i, 0, n) {
        forn (j, 0, n) {
            if (gr[i][j] == 'a') {
                out_a[i].pb(j);
                in_a[j].pb(i);
            }
            if (gr[i][j] == 'b') {
                out_b[i].pb(j);
                in_b[j].pb(i);
            }
        }
    }
    forn (i, 0, n) {
        if (in_a[i].size() >= 1 && out_a[i].size() >= 1) {
            int x = in_a[i].back(), y = out_a[i].back();
            vector<int> ans(m + 1);
            for (int j = m / 2; j >= 0; j -= 2)
                ans[j] = i;
            for (int j = m / 2 - 1; j >= 0; j -= 2)
                ans[j] = x;
            for (int j = m / 2; j < ans.size(); j += 2)
                ans[j] = i;
            for (int j = m / 2 + 1; j < ans.size(); j += 2)
                ans[j] = y;
            cout << "YES\n";
            for (int t : ans)
                cout << t + 1 << " ";
            cout << "\n";
            return;
        }
        if (in_b[i].size() >= 1 && out_b[i].size() >= 1) {
            int x = in_b[i].back(), y = out_b[i].back();
            vector<int> ans(m + 1);
            for (int j = m / 2; j >= 0; j -= 2)
                ans[j] = i;
            for (int j = m / 2 - 1; j >= 0; j -= 2)
                ans[j] = x;
            for (int j = m / 2; j < ans.size(); j += 2)
                ans[j] = i;
            for (int j = m / 2 + 1; j < ans.size(); j += 2)
                ans[j] = y;
            cout << "YES\n";
            for (int t : ans)
                cout << t + 1 << " ";
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}