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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int prev = -1;
    vector <vector <pii>> segments(3);
    forn (i, 0, n) {
        if (s[i] == 'W') {
            int len = i - prev - 1;
            if (prev == -1)
                segments[0].eb(prev + 1, i - 1);   
            else
                segments[2].eb(prev + 1, i - 1);
            prev = i;
        }
    }
    segments[1].eb(prev + 1, n - 1);
    for (int i = 2; i >= 0; --i) {
        sort(all(segments[i]), [](pii a, pii b) {
            return a.sc - a.fs < b.sc - b.fs;
        });
        for (auto [l, r] : segments[i]) {
            if (i == 0) {
                for (int t = r; t >= l; --t) {
                    if (k) {
                        s[t] = 'W';
                        --k;
                    }
                }
            } else {
                forn (t, l, r + 1) {
                    if (k) {
                        s[t] = 'W';
                        --k;
                    }
                }
            }
        }
    }
    int ans = 0;
    forn (i, 0, n) {
        if (s[i] == 'W') {
            ++ans;
            if (i > 0 && s[i - 1] == 'W')
                ++ans;
        }
    }
    cerr << s << "\n";
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
       cin >> t;
       while (t --> 0)
           solve();   
    return 0;
}