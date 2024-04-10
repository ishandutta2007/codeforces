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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    vector<int> up_left(n), up_right(n), down_left(n), down_right(n);
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            up_right[i] = down_right[i] = 1;
            continue;
        }
        if (p[i] < p[i + 1]) {
            up_right[i] = up_right[i + 1] + 1;
            down_right[i] = 1;
        } else {
            up_right[i] = 1;
            down_right[i] = down_right[i + 1] + 1;
        }
    }
    forn (i, 0, n) {
        if (i == 0) {
            up_left[i] = down_left[i] = 1;
            continue;
        }
        if (p[i] < p[i - 1]) {
            up_left[i] = up_left[i - 1] + 1;
            down_left[i] = 1;
        } else {
            up_left[i] = 1;
            down_left[i] = down_left[i - 1] + 1;
        }
    }
    cerr << up_left << "\n" << up_right << "\n" << down_left << "\n" << down_right << "\n";
    int mx = 0;
    forn (i, 0, n)
        chkmax(mx, max(up_left[i], up_right[i]));
    int cnt = 0;
    forn (i, 0, n) {
        if (up_left[i] == mx)
            ++cnt;
        if (up_right[i] == mx)
            ++cnt;
    }
    if (cnt != 2) {
        cout << "0\n";
        return 0;
    }
    bool peak_exists = false;
    forn (i, 0, n)
        if (down_left[i] == mx && down_right[i] == mx)
            peak_exists = true;
    if (peak_exists && mx % 2 == 1)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}