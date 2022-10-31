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
    cin >> n;
    vector<int> a(n);
    cin >> a;
    forn (i, 0, n) {
        --a[i];
    }
    vector<int> ans(n, -1);
    vector<int> rev(n, -1);
    auto add_link = [&](int from, int to) {
        ans[from] = to;
        rev[to] = from;
    };
    int cnt_good = 0;
    forn (i, 0, n) {
        if (rev[a[i]] == -1) {
            ++cnt_good;
            add_link(i, a[i]);
        }
    }
    cerr << ans << "\n";
    cerr << rev << "\n";
    forn (i, 0, n) {
        if (ans[i] == -1 &&
            rev[i] == -1) {
            int t = rev[a[i]];
            add_link(i, ans[t]);
            add_link(t, i);
            // ans[i] = rev[a[i]];
            // ans[rev[a[i]]] = i;
        }
    }
    cerr << ans << "\n";
    cerr << rev << "\n";
    set<int> x;
    forn (i, 0, n) {
        if (ans[i] == -1) {
            cerr << i << " ";
            x.insert(i);
        }
    }
    cerr << "\n";
    set<int> y;
    forn (i, 0, n) {
        if (rev[i] == -1) {
            y.insert(i);
            cerr << i << " ";
        }
    }
    for (int elem : x) {
        ans[elem] = *y.begin();
        y.erase(y.begin());
    }
    cerr << "\n\n";
    cout << cnt_good << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
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