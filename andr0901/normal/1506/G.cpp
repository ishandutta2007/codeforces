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

constexpr int M = 26;

void solve() {
    string s;
    cin >> s;
    vector<deque<int>> occurences(M);
    forn (i, 0, sz(s))
        occurences[s[i] - 'a'].pb(i);
    string ans;
    while (true) {
        int lst = -1;
        for (int i = M - 1; i >= 0; --i) {
            if (occurences[i].empty())
                continue;
            int t = occurences[i][0];
            bool ok = true;
            forn (j, 0, M)
                if (!occurences[j].empty() && occurences[j].back() < t)
                    ok = false;
            if (ok) {
                ans += (char)(i + 'a');
                occurences[i].clear();
                lst = i;
                forn (j, 0, M) {
                    while (!occurences[j].empty() && occurences[j].front() < t) {
                        occurences[j].pop_front();
                    }
                }
                break;
            }
        }
        if (lst == -1) {
            cout << ans << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}