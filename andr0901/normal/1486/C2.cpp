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

int ask(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans - 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int sc = ask(0, n - 1);
    if (sc == 0 || (sc != n - 1 && ask(sc, n - 1) == sc)) {
        int l = sc, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ask(0, m) == sc)
                r = m;
            else
                l = m;
        }
        cout << "! " << r + 1 << endl;
    } else {
        int l = 0, r = sc;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ask(m, n - 1) == sc)
                l = m;
            else
                r = m;
        }
        cout << "! " << l + 1 << endl;
    }
    return 0;
}