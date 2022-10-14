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
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 250001, logN = 18;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) return cout << 0 << endl, 0;
    }
    set <int> s;
    for (int i = 0; i < n; ++i) s.insert(a[i]);
    for (int i = 0; i < n; ++i) {
        int tmp = a[i] & x;
        if (a[i] != tmp && s.count(tmp)) {
            cout << 1 << endl;
            return 0;
        }
    }
    s.clear();
    for (int i = 0; i < n; ++i) {
        int tmp = a[i] & x;
        if (s.count(tmp)) {
            cout << 2 << endl;
            return 0;
        }
        s.insert(tmp);
    }
    cout << -1 << endl;
}