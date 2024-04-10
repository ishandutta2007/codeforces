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

vector <int> get_cnt(const string& a) {
    vector <int> cnt(26);
    for (char c : a)
        cnt[c - 'a']++;
    return cnt;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> b >> a;
    auto cnt_a = get_cnt(a), cnt_b = get_cnt(b);
    forn (i, 0, 26) {
        if (cnt_b[i] >= cnt_a[i] &&
            cnt_a[i] % k == cnt_b[i] % k) {
            if (i != 25)
                cnt_b[i + 1] += (cnt_b[i] - cnt_a[i]);
        } else {
            cerr << i << "\n";
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}