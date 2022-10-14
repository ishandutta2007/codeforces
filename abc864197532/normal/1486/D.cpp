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
const int mod = 1e9 + 7, abc = 864197532, N = 10100101, logN = 17, K = 333, INF = 5e8;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto check = [&](int x) {
        vector <int> pre = {0};
        for (int i = 0; i < n; ++i) pre.pb(pre.back() + (a[i] >= x));
        bool is = false;
        // same
        {
            int mn[2] = {1 << 30, 1 << 30};
            for (int i = k; i <= n; i++) {
                mn[(i - k) & 1] = min(mn[(i - k) & 1], pre[i - k] - (i - k) / 2);
                if ((pre[i] - i / 2) - mn[i & 1] - 1 >= 0) is = true;
            }
        }
        // diff
        {
            int mn[2] = {1 << 30, 1 << 30};
            for (int i = k; i <= n; i++) {
                mn[(i - k) & 1] = min(mn[(i - k) & 1], pre[i - k] - (i - k) / 2);
                if ((pre[i] - i / 2) - mn[i & 1 ^ 1] - 1 + (i & 1 ^ 1) >= 0) is = true;
            }
        }
        return is;
    };
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}