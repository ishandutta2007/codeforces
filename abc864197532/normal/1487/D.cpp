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
const int mod = 1e9 + 7, abc = 864197532, N = 20, logN = 17, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
     * a^2 = b + c;
     * c^2 - c = b + b^2
     * c(c - 1) = b(b + 1)
     * c = b + 1
     * a^2 = 2b + 1;
     */
    int t;
    cin >> t;
    vector <long long> v;
    for (long long i = 3; i <= 69999; i += 2) {
        long long c = (i * i + 1) / 2, b = (i * i - 1) / 2;
        v.pb(c);
    }
    while (t--) {
        int n;
        cin >> n;
        cout << upper_bound(all(v), n) - v.begin() << endl;
    }
}