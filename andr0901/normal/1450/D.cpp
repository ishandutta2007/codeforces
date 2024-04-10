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
    vector<int> cnt(n + 1);
    vector<int> a(n);
    cin >> a;
    forn (i, 0, n)
        cnt[a[i]]++;
    auto check_first = [&]() {
        vector<int> b = a;
        sort(all(b));
        vector<int> needed(n);
        iota(all(needed), 1);
        cout << (b == needed);
    };
    check_first();
    int lst = 0, cur_len = n + 1;
    deque<int> q(a.begin(), a.end());
    while (q.size()) {
        ++lst;
        --cur_len;
        if (cnt[lst - 1] > 1) {
            break;
        }
        if (q.front() == lst) {
            q.pop_front();
        } else if (q.back() == lst) {
            q.pop_back();
        } else {
            break;
        }
    }
    cerr << lst << " ";
    if (!q.empty() && *min_element(all(q)) == lst && q.size() == cur_len) {
        ++lst;
    }
    cerr << lst << " ";
    forn (i, 0, n - lst)
        cout << '0';
    forn (i, 0, lst - 1)
        cout << '1';
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