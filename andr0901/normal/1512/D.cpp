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

bool check(vector<int>& a, int sum) {
    cerr << a << ": " << sum << "\n";
    long long real_sum = accumulate(all(a), 0LL);
    forn (i, 0, sz(a)) {
        if (real_sum - a[i] == sum) {
            forn (j, 0, sz(a)) {
                if (i != j)
                    cout << a[j] << " ";
            }
            cout << "\n";
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    cin >> a;
    sort(all(a));
    int t = a.back();
    a.pop_back();
    if (check(a, t))
        return;
    int l = a.back();
    a.pop_back();
    a.push_back(t);
    if (check(a, l))
        return;
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}