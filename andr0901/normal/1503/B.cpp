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

ostream& operator<<(ostream& out, pii& a)  {out << a.fs << " " << a.sc; return out;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pii>> colors(2);
    forn (i, 0, n)
        forn (j, 0, n)
            colors[(i + j) % 2].eb(i + 1, j + 1);
    forn (i, 0, n * n) {
        int t;
        cin >> t;
        --t;
        if (t == 0) {
            if (colors[1].empty()) {
                cout << "3 " << colors[0].back();
                colors[0].pop_back();
            } else {
                cout << "2 " << colors[1].back();
                colors[1].pop_back();
            }
        } else if (t == 1) {
            if (colors[0].empty()) {
                cout << "3 " << colors[1].back();
                colors[1].pop_back();
            } else {
                cout << "1 " << colors[0].back();
                colors[0].pop_back();
            }
        } else {
            if (colors[0].empty()) {
                cout << "2 " << colors[1].back();
                colors[1].pop_back();
            } else {
                cout << "1 " << colors[0].back();
                colors[0].pop_back();
            }
        }
        cout << endl;
    }
    return 0;
}