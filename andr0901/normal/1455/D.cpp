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

constexpr int INF = 1e9;

bool good(vector <int>& a) {
    forn (i, 1, sz(a))
        if (a[i - 1] > a[i])
            return false;
    return true;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    cin >> a;
    if (good(a)) {
        cout << "0\n";
        return;
    }
    int ans = INF;
    forn (i, 0, n) {
        cerr << i << ":\n";
        int final_x = a[i];
        vector <int> needed = a;
        needed[i] = x;
        sort(all(needed));
        cerr << needed << "\n";
        map <int, vector <int>> where;
        forn (j, 0, n)
            where[needed[j]].pb(j);
        auto cur_a = a;
        int cur_x = x;
        int cnt = 0;
        cerr << cur_a << "  " << cur_x << "\n";
        while (cur_x < final_x) {
            bool done = false;
            for (int k : where[cur_x])
                if (cur_a[k] != cur_x) {
                    cerr << k << ": ";
                    int new_x = cur_a[k];
                    if (new_x > cur_x) {
                        done = true;
                        ++cnt;
                        cur_a[k] = cur_x;
                        cur_x = new_x;
                        break;
                    }
                }
            cerr << cur_a << "  " << cur_x << "\n";
            if (!done)
                break;
        }
        if (good(cur_a))
            chkmin(ans, cnt);
        cerr << "\n";
    }
    cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}