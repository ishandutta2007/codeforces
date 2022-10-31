#pragma GCC optimize("Ofast")
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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    a.pb(a[0]);
    bool mono = true;
    forn (i, 0, n)
        if (a[i] != a[i + 1])
            mono = false;
    if (mono) {
        cout << "1\n";
        forn (i, 0, n)
            cout << "1 ";
        cout << "\n";
        return;
    }
    if (n % 2 == 0) {
        cout << "2\n";
        forn (i, 0, n) {
            if (i % 2)
                cout << "1 ";
            else
                cout << "2 ";
        }
        cout << "\n";
        return;
    } else {
        forn (i, 0, n - 1) {
            if (a[i] == a[i + 1]) {
                cout << "2\n";
                forn (j, 0, i + 1) {
                    if (j % 2)
                        cout << "1 ";
                    else
                        cout << "2 ";
                }
                if (i % 2)
                    cout << "1 ";
                else
                    cout << "2 ";
                forn (j, i + 2, n)
                    if (j % 2)
                        cout << "2 ";
                    else
                        cout << "1 ";
                cout << "\n";
                return;
            }
        }
        if (a[0] == a[n - 1]) {
            cout << "2\n";
            forn (j, 0, n) {
                if (j % 2)
                    cout << "1 ";
                else
                    cout << "2 ";
            }
            cout << "\n";
            return;
        }
        cout << "3\n";
        forn (i, 0, n - 1) {
            if (i % 2)
                cout << "1 ";
            else
                cout << "2 ";
        }
        cout << "3\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}