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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

bool ask(lli l, lli r) {
    cout << l << ' ' << r << endl;
    string s;
    cin >> s;
    if (l == r && s == "Yes") exit(0);
    return s == "Yes";
}

int main () {
    // 45000
    lli n, k;
    cin >> n >> k;
    lli l = 1, r = n + 1;
    int t = 4500;
    while (t--) {
        if (r - l <= k * 4 + 7) {
            lli tmp = uniform_int_distribution<lli>(l, r - 1)(rng);
            ask(tmp, tmp);
            l = max(l - k, 1ll);
            r = min(r + k, n + 1);
        } else {
            lli mid = l + r >> 1;
            if (ask(l, mid - 1)) {
                r = mid;
            } else {
                l = mid;
            }
            l = max(l - k, 1ll);
            r = min(r + k, n + 1);
        }
    }
}