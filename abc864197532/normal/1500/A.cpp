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
const int mod = 998244353, abc = 864197532, N = 5010, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <pii> now(5000001, mp(-1, -1));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < i; ++j) {
            int k = a[i] + a[j];
            if (now[k].X != -1 && now[k].X != i && now[k].Y != i && now[k].X != j && now[k].Y != j) {
                cout << "YES\n";
                cout << i + 1 << ' ' << j + 1 << ' ' << now[k].X + 1 << ' ' << now[k].Y + 1 << endl;
                return 0;
            }
            now[a[i] + a[j]] = mp(i, j);
        }
    }
    cout << "NO\n";
}