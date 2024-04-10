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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector <int> delta(2 * d + 1);
    forn (i, a, b + 1) {
        delta[i + b]++;
        delta[i + c + 1]--;
    }
    long long ans = 0;
    int cur = 0;
    forn (i, 0, 2 * d + 1) {
        cur += delta[i];
        //cout << i << " " << cur << "\n";
        if (i > d)
            ans += 1LL * (d - c + 1) * cur;
        else if (i <= c)
            continue;
        else
            ans += 1LL * (i - c) * cur;
        //cout << ans << " ";
    }
    cout << ans;
    return 0;
}