#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 100001, logN = 18;

vector <int> f[N];
int jump[N][logN];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < N; ++i) if (f[i].empty()) for (int j = i; j < N; j += i) f[j].pb(i);
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> lst(N, n);
    vector <int> r(n);
    for (int i = n - 1; ~i; --i) {
        int res = i + 1 < n ? r[i + 1] : n;
        for (int j : f[a[i]]) res = min(res, lst[j]);
        r[i] = res;
        for (int j : f[a[i]]) lst[j] = i;
    }
    for (int i = 0; i < n; ++i) jump[i][0] = r[i];
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i < n; ++i) {
            if (jump[i][j - 1] == n) jump[i][j] = n;
            else jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r, --l;
        int ans = 0;
        for (int i = logN - 1; ~i; --i) {
            if (jump[l][i] < r) ans += 1 << i, l = jump[l][i];
        }
        cout << ans + 1 << '\n';
    }
}