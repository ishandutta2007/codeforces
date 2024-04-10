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
const int mod = 1e9 + 7, abc = 864197532, N = 400008, logN = 17, K = 333;

int mask[20];

bool add(int x) {
    for (int i = 19; ~i; --i) if (x & (1 << i)) {
        if (!mask[i]) {
            mask[i] = x;
            return true;
        }
        x ^= mask[i];
    }
    return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <pii> Q[n];
    for (int i = 0, l, x; i < q; ++i) {
        cin >> l >> x, l--;
        Q[l].eb(x, i);
    }
    vector <int> ans(q);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += add(a[i]);
        for (pii A : Q[i]) {
            int x = A.X;
            for (int j = 19; ~j; --j) if (x & (1 << j)) {
                if (!mask[j]) break;
                else x ^= mask[j];
            }
            if (x) ans[A.Y] = -1;
            else ans[A.Y] = i + 1 - cnt;
        }
    }
    lli pw2[n + 1];
    pw2[0] = 1;
    for (int i = 0; i < n; ++i) pw2[i + 1] = pw2[i] * 2 % mod;
    for (int i : ans) cout << (~i ? pw2[i] : 0) << '\n';
}