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
    vector <int> a(n);
    cin >> a;
    forn (i, 1, n) {
        int t = (a[i - 1] ^ a[i]);
        if (i - 2 >= 0 &&
            a[i - 2] > t)
            return cout << 1, 0;
        if (i + 1 < n &&
            t > a[i + 1])
            return cout << 1, 0;
    }
    int ans = 1e9;
    forn (i, 0, n) {
        int l = 0, cnt_l = -1;
        for (int j = i; j >= 0; --j) {
            l ^= a[j];
            ++cnt_l;
            int r = 0, cnt_r = -1;
            forn (k, i + 1, n) {
                r ^= a[k];
                ++cnt_r;
                if (l > r) {
                    chkmin(ans, cnt_l + cnt_r);
                }
                cerr << i << " " << j << " " << k << ": " << l << " " << r  << "\n";
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}