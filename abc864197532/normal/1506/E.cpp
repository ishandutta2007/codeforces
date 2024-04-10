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
const int mod = 1e9 + 7, abc = 864197532, N = 1000, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        {
            vector <int> ans(n, -1);
            vector <bool> choose(n + 1, false);
            choose[a[0]] = true;
            ans[0] = a[0];
            for (int i = 1; i < n; ++i) if (a[i - 1] ^ a[i]) {
                choose[a[i]] = true;
                ans[i] = a[i];
            }
            int now = 1;
            for (int i = 0; i < n; ++i) if (ans[i] == -1) {
                while (choose[now]) now++;
                ans[i] = now;
                choose[now] = true;
            }
            printv(ans);
        }
        {
            vector <int> ans(n, -1);
            set <int> choose;
            for (int i = 1; i <= n; ++i) choose.insert(i);
            choose.erase(a[0]);
            ans[0] = a[0];
            for (int i = 1; i < n; ++i) if (a[i - 1] ^ a[i]) {
                choose.erase(a[i]);
                ans[i] = a[i];
            }
            for (int i = 0; i < n; ++i) if (ans[i] == -1) {
                auto it = choose.upper_bound(a[i]);
                ans[i] = *--it;
                choose.erase(it);
            }
            printv(ans);
        }
    }
}