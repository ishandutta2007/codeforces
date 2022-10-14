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
const int mod = 1e9 + 7, abc = 864197532, N = 5001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, q;
    cin >> n >> k >> a >> q;
    vector <int> Q(q);
    for (int i = 0; i < q; ++i) cin >> Q[i], --Q[i];
    auto check = [&](int len) {
        vector <int> pre(n - a + 2, 0);
        for (int i = 0; i < len; ++i) {
            pre[max(Q[i] - a + 1, 0)]++;
            pre[min(Q[i], n - a) + 1]--;
        }
        for (int i = 1; i < n - a + 2; ++i) pre[i] += pre[i - 1];
        int cnt = 0;
        for (int i = 0; i <= n - a; ++i) {
            if (!pre[i]) cnt++, i += a;
        }
        return cnt >= k;
    };
    int l = 0, r = q + 1;
    while (r - l > 1) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    if (check(q)) cout << -1 << endl;
    else cout << l + 1 << endl;
}