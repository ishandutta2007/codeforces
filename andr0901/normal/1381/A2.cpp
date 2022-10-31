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
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector <int> ans;
    int cur = 0;
    forn (i, 0, n) {
        int j = i;
        while (j < n && a[j] == a[i])
            ++j;
        ans.pb(j - 1);
        i = j - 1;
    }
    ans.pop_back();
    if (a[n - 1] != b[n - 1])
        ans.push_back(n - 1);
    for (int i = n - 1; i >= 0; --i) {
        int j = i;
        while (j >= 0 && b[j] == b[i])
            --j;
        ans.pb(j);
        i = j + 1;
    }
    ans.pop_back();
    cout << sz(ans) << " ";
    for (int x : ans)
        cout << x + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}