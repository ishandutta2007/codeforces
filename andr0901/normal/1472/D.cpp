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
    multiset<int> even, odd;
    forn (i, 0, n)
        if (a[i] % 2)
            odd.insert(a[i]);
        else
            even.insert(a[i]);
    long long sum_even = 0, sum_odd = 0;
    bool turn_even = true;
    while (!even.empty() && !odd.empty()) {
        if (turn_even) {
            if (*even.rbegin() > *odd.rbegin()) {
                sum_even += *even.rbegin();
                even.erase(--even.end());
            } else {
                odd.erase(--odd.end());
            }
        } else {
            if (*even.rbegin() < *odd.rbegin()) {
                sum_odd += *odd.rbegin();
                odd.erase(--odd.end());
            } else {
                even.erase(--even.end());
            }
        }
        turn_even = !turn_even;
    }
    while (!even.empty()) {
        if (turn_even) {
            sum_even += *even.rbegin();
            even.erase(--even.end());
        } else {
            even.erase(--even.end());
        }
        turn_even = !turn_even;
    }
    while (!odd.empty()) {
        if (turn_even) {
            odd.erase(--odd.end());
        } else {
            sum_odd += *odd.rbegin();
            odd.erase(--odd.end());
        }
        turn_even = !turn_even;
    }
    cerr << sum_even << " " << sum_odd << "\n";
    if (sum_even > sum_odd)
        cout << "Alice";
    else if (sum_even == sum_odd)
        cout << "Tie";
    else
        cout << "Bob";
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