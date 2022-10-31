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
/*
int ans = 0;
int needed;

void solve(int sum, int i) {
    if (i == 5) {
        if (sum == needed)
            ++ans;
        return;
    }
    forn (j, 0, 8)
        solve(sum + (1 << i) * j, i + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    forn (i, 1, 25) {
        ans = 0;
        needed = i;
        solve(0, 0);
        cout << i << ": " <<  ans << "\n";
    }
    return 0;
}
*/
/*
1: 1
2: 2
3: 2
4: 4
5: 4
6: 6
7: 6
8: 9
9: 9
10: 12
11: 12
12: 16
13: 16
14: 20
15: 20
16: 25
17: 25
18: 30
19: 30
20: 36
21: 36
22: 42
23: 42
24: 49
*/

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    int t = bin_pow(a, p / 2);
    return (1LL * t * t) % MOD;
}

int inv(int x) {
    return bin_pow(x, MOD - 2);
}


void solve() {
    long long x;
    cin >> x;
    long long k = (x + 2) / 4;
    k %= MOD;
    if (x % 4 == 2 || x % 4 == 3)
        cout << mul(k, k + 1);
    else
        cout << add(mul(k, k + 1), k + 1);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}