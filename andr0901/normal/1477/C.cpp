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

#define int long long

int dst(pii a, pii b) {
    return (a.fs - b.fs) * (a.fs - b.fs) + (a.sc - b.sc) * (a.sc - b.sc);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<pii> a(n);
    forn (i, 0, n)
        cin >> a[i].fs >> a[i].sc;
    pii last = {1e9 + 5, 1e9 + 5};
    vector<bool> used(n);
    forn (i, 0, n) {
        int best = -1, best_idx = -1;
        forn (j, 0, n) {
            if (!used[j]) {
                auto d = dst(last, a[j]);
                if (d > best) {
                    best = d;
                    best_idx = j;
                }
            }
        }
        last = a[best_idx];
        used[best_idx] = true;
        cout << best_idx + 1 << " ";
    }
    return 0;
}