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

int solve(int l, int r) {
    if (l == r) {
        return l;
    }
    if (r - l == 1) {
        int t = ask(l, r);
        if (l == t)
            return r;
        else
            return l;
    }
    if (r - l == 2) {
        int t = ask(l, l + 1);
        int mx;
        if (t == l)
            mx = l + 1;
        else
            mx = l;
        t = ask(l, r);
        if (t == mx)
            return l + 2;
        else
            return mx;
    }
    int m = (l + r) / 2;
    int fs = ask(l, r);
    if (fs <= m) {
        int sc = ask(l, m);
        if (sc == fs)
            return solve(l, m);
        else
            return solve(m + 1, r); 
    } else {
        int sc = ask(m + 1, r);
        if (sc == fs)
            return solve(m + 1, r);
        else
            return solve(l, m);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int t = solve(0, n - 1);
    cout << "! " << t + 1 << endl;
    return 0;
}