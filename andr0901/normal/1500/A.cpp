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

constexpr int M = 3e6 + 5;

bool sim(int a, int b, int c, int d) {
    return a == c  || a == d || b == c || b == d;
}

void solve_unique(vector<pii>& a) {
    vector<pii> sum(2 * M, {-1, -1});
    forn (i, 0, sz(a)) {
        forn (j, i + 1, sz(a)) {
            int x = a[i].fs + a[j].fs;
            if (sum[x].fs != -1) {
                cout << "YES\n";
                cout << sum[x].fs + 1 << " " << sum[x].sc + 1 << " " << a[i].sc + 1 << " " << a[j].sc + 1 << "\n";
                exit(0);
            }
            sum[x] = {a[i].sc, a[j].sc};
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> cnt(M);
    forn (i, 0, n)
        cnt[a[i]].pb(i);
    vector<pii> uniqued;
    forn (i, 0, M)
        if (!cnt[i].empty())
            uniqued.eb(i, cnt[i][0]);
    solve_unique(uniqued);
    vector<int> two_plus;
    forn (i, 0, M) {
        if (cnt[i].size() >= 2)
            two_plus.pb(i);
        if (cnt[i].size() >= 4) {
            cout << "YES\n";
            forn (k, 0, 4)
                cout << cnt[i][k] + 1 << " ";
            cout << "\n";
            return 0;
        }
    }
    if (two_plus.size() >= 2) {
        cout << "YES\n";
        int i = two_plus[0], j = two_plus[1];
        cout << cnt[i][0] + 1 << " " << cnt[j][0] + 1 << " " << cnt[i][1] + 1 << " " << cnt[j][1] + 1 << "\n";
        return 0;
    }
    if (two_plus.size() == 0) {
        cout << "NO\n";
        return 0;
    }
    int needed = two_plus[0];
    forn (i, 0, sz(uniqued)) {
        forn (j, i + 1, sz(uniqued)) {
            if (uniqued[i].fs + uniqued[j].fs == 2 * needed) {
                cout << "YES\n";
                cout << uniqued[i].sc + 1 << " " << uniqued[j].sc + 1 << " " << cnt[needed][0] + 1 << " " << cnt[needed][1] + 1 << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}