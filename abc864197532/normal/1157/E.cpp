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
const int mod = 1e9 + 7, abc = 864197532, N = 100001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> m1;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0, x; i < n; ++i) cin >> x, m1[x]++;
    for (int i = 0; i < n; ++i) {
        int best = (n - a[i]) % n;
        auto it = m1.lower_bound(best);
        if (it == m1.end()) {
            it = m1.lower_bound(0);
        }
        cout << (a[i] + it->X) % n << ' ';
        m1[it->X]--;
        if (!m1[it->X]) m1.erase(it);
    }
    cout << endl;
}