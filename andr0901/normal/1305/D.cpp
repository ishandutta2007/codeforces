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

vector <set <int>> gr;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].insert(u), gr[u].insert(v);
    }
    forn (i, 0, n / 2) {
        vector <int> leaves;
        forn (j, 0, n)
            if (gr[j].size() == 1)
                leaves.pb(j);
        cout << "? " << leaves[0] + 1 << " " << leaves[1] + 1 << endl;
        int ans;
        cin >> ans, --ans;
        if (ans == leaves[0] || ans == leaves[1])
            return cout << "! " << ans + 1 << endl, 0;
        gr[*gr[leaves[0]].begin()].erase(leaves[0]);
        gr[leaves[0]].clear();
        gr[*gr[leaves[1]].begin()].erase(leaves[1]);
        gr[leaves[1]].clear();
        if (i == n / 2 - 1)
            return cout << "! " << ans + 1 << endl, 0;
    }
    return 0;
}