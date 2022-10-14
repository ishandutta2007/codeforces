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
const int mod = 998244353, abc = 864197532, N = 500087, logN = 20, K = 333;

lli dis(pll a, pll b) {
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> ans = {0};
    vector <bool> choose(n, false);
    choose[0] = true;
    for (int _t = 1; _t < n; ++_t) {
        int j = ans.back();
        int k = -1;
        for (int i = 0; i < n; ++i) if (!choose[i]) {
            if (k == -1 || dis(a[j], a[k]) < dis(a[j], a[i])) k = i;
        }
        ans.pb(k);
        choose[k] = true;
    }
    for (int i : ans) cout << i + 1 << ' ';
    cout << endl;
}