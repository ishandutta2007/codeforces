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

char zero;
char one;

vector<int> get(const string& a) {
    vector<int> ans;
    int cur = 0;
    for (char c : a) {
        if (c == zero) {
            ++cur;
        } else {
            ans.pb(cur);
            cur = 0;
        }
    }
    ans.pb(cur);
    return ans;
}

string trial(const string& a, const string& b) {
    auto x = get(a);
    auto y = get(b);
    if (x.size() > y.size()) {
        swap(x, y);
    }
    string ans = "";
    forn (i, 0, x.size()) {
        int cnt = max(x[i], y[i]);
        if (i != 0) {
            ans += one;
        }
        ans += string(cnt, zero);
    }
    forn (i, x.size(), y.size()) {
        int cnt = y[i];
        if (i != 0) {
            ans += one;
        }
        ans += string(cnt, zero);
    }
    return ans;
}

void solve() {
    int n;
    vector<string> a(3);
    cin >> n >> a;
    zero = '0';
    one = '1';
    forn (i, 0, 3) {
        forn (j, i + 1, 3) {
            auto ans = trial(a[i], a[j]);
            cerr << a[i] << "\n" << a[j] << ":\n" << ans << "\n\n";
            if (ans.size() <= 3 * n) {
                cout << ans << "\n";
                return;
            }
        }
    }
    swap(one, zero);
    forn (i, 0, 3) {
        forn (j, i + 1, 3) {
            auto ans = trial(a[i], a[j]);
            cerr << a[i] << "\n" << a[j] << ":\n" << ans << "\n\n";
            if (ans.size() <= 3 * n) {
                cout << ans << "\n";
                return;
            }
        }
    }
    cerr << "FUCK\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}