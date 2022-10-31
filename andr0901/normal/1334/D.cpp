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

#define int long long

int n, l, r;

int get_pos(int M) {
    return 2 * n * M - 2 * M * (M + 1) / 2;
}

void solve() {
    cin >> n >> l >> r;
    --l;
    int L = 0, R = n;
    while (R - L > 1) {
        int M = L + R >> 1;
        if (get_pos(M) <= l)
            L = M;
        else
            R = M;
    }
    //cout << L << " " << get_pos(L) << "\n";
    int i = L, j = L + 1;
    int pos = get_pos(L);
    while (pos + 1 < l) {
        ++j;
        pos += 2;
        if (j == n) {
            ++i;
            j = i + 1;
        }
    }
    if (pos < l) {
        cout << j + 1 << " ";
        ++j;
        if (j == n) {
            ++i;
            j = i + 1;
        }
        pos += 2;
    }
    while (pos + 1 < r) {
        cout << i + 1 << " " << j + 1 << " ";
        ++j;
        pos += 2;
        if (j == n) {
            ++i;
            j = i + 1;
        }
    }
    if (pos < r) {
        if (i == n - 1)
            cout << "1 ";
        else
            cout << i + 1 << " "; 
    }
    cout << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}