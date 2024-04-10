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
    cin >> s;
    vector <int> cnt(10);
    for (char digit : s)
        cnt[digit - '0']++;
    int ans = *max_element(all(cnt));
    forn (i, '0', '9' + 1) {
        forn (j, '0', '9' + 1) {
            if (i == j)
                continue;
            // cerr << i << " " << j << "\n";
            int k = 0, cur = 0;
            while (k != s.size()) {
                while (k != s.size() && s[k] != i)
                    ++k;
                bool ok = (k != s.size());
                while (k != s.size() && s[k] != j)
                    ++k;
                ok = (ok & (k != s.size()));
                if (ok)
                    cur += 2;
                // if (i == '0' + 1 && j == '0' + 0)
                //     cerr << k << "\n";
            }
            // if (cur > ans)
            //     cerr << i - '0' << " " << j - '0' << " " << cur << "\n";
            chkmax(ans, cur);
        }
    }
    cout << sz(s) - ans << "\n";
    // cerr << "\n---\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}

/*
2 = n
3 = 1
4 = 2
...
n = n - 2
1 = n - 1

n = n - 2 = n - 4 ...
1 = 3 = 5 = ...
*/