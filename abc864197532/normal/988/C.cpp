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
const int mod = 1e9 + 7, abc = 864197532, N = 100005, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    vector <vector <int>> a(m);
    map <int, pii> m1;
    for (int i = 0, n; i < m; ++i) {
        cin >> n;
        a[i].resize(n);
        int sum = 0;
        for (int &j : a[i]) cin >> j, sum += j;
        for (int j = 0; j < n; ++j) {
            sum -= a[i][j];
            if (m1.count(sum)) {
                int g, id;
                tie(g, id) = m1[sum];
                if (g != i) {
                    cout << "YES\n";
                    cout << g + 1 << ' ' << id + 1 << endl;
                    cout << i + 1 << ' ' << j + 1 << endl;
                    return 0;
                }
            } else {
                m1[sum] = mp(i, j);
            }
            sum += a[i][j];
        }
    }
    cout << "NO\n";
}