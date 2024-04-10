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

#define int long long

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
        return cout << "0", 0;
    if (a == b)
        return cout << "1\n" << a, 0;
    if (a % 2 != b % 2 || a > b)
        return cout << "-1", 0;

    vector <int> ans(2);
    int remain = b;
    for (int i = 60; i >= 0; --i) {
        if ((a >> i) & 1) {
            ans[0] |= (1LL << i);
            remain -= (1LL << i);
        } else {
            if (remain >= 2 * (1LL << i)) {
                ans[0] |= (1LL << i);
                ans[1] |= (1LL << i);
                remain -= 2 * (1LL << i);
            }
        }
        if (remain < 0)
            break;
    }
    if (remain != 0) {
        cout << "3\n";
        cout << a << " " << (b - a) / 2 << " " << (b - a) / 2;
    } else {
        cout << "2\n";
        cout << ans;
    }
    return 0;
}