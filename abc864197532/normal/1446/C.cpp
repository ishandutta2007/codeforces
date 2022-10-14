#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 1 << 20;

vector <int> a;

int solve(int l, int r, int b) {
    if (l == r) return 0;
    if (b < 0) return r - l - 1;
    int p = l;
    while (p < r && !(a[p] & (1 << b))) p++;
    if (p == l || p == r) return solve(l, r, b - 1);
    return min(solve(l, p, b - 1) + r - p - 1, solve(p, r, b - 1) + p - l - 1);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    fop (i,0,n) cin >> a[i];
    sort(all(a));
    cout << solve(0, n, 30);
}