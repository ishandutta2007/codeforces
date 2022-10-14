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
const int mod = 1e9 + 7, abc = 864197532, N = 20, logN = 17, K = 333, INF = 5e8;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n1, n2, n3, n4, m1, m2, m3;
    cin >> n1 >> n2 >> n3 >> n4;
    vector <int> a(n1 + 1), b(n2 + 1), c(n3 + 1), d(n4 + 1);
    for (int i = 1; i <= n1; ++i) cin >> a[i];
    for (int i = 1; i <= n2; ++i) cin >> b[i];
    for (int i = 1; i <= n3; ++i) cin >> c[i];
    for (int i = 1; i <= n4; ++i) cin >> d[i];
    cin >> m1;
    vector <vector <int>> A(n2 + 1);
    for (int i = 0, x, y; i < m1; ++i) cin >> x >> y, A[y].pb(x);
    cin >> m2;
    vector <vector <int>> B(n2 + 1);
    for (int i = 0, x, y; i < m2; ++i) cin >> x >> y, B[x].pb(y);
    cin >> m3;
    vector <vector <int>> C(n3 + 1);
    for (int i = 0, x, y; i < m3; ++i) cin >> x >> y, C[x].pb(y);
    vector <int> left(n2 + 1), right(n3 + 1);
    multiset <int> cur;
    cur.insert(INF);
    for (int i = 1; i <= n1; ++i) cur.insert(a[i]);
    for (int i = 1; i <= n2; ++i) {
        for (int j : A[i]) cur.erase(cur.lower_bound(a[j]));
        left[i] = *cur.begin() + b[i];
        for (int j : A[i]) cur.insert(a[j]);
    }
    cur.clear();
    cur.insert(INF);
    for (int i = 1; i <= n4; ++i) cur.insert(d[i]);
    for (int i = 1; i <= n3; ++i) {
        for (int j : C[i]) cur.erase(cur.lower_bound(d[j]));
        right[i] = *cur.begin() + c[i];
        for (int j : C[i]) cur.insert(d[j]);
    }
    cur.clear();
    cur.insert(INF);
    int ans = INF;
    for (int i = 1; i <= n3; ++i) cur.insert(right[i]);
    for (int i = 1; i <= n2; ++i) {
        for (int j : B[i]) cur.erase(cur.lower_bound(right[j]));
        ans = min(ans, *cur.begin() + left[i]);
        for (int j : B[i]) cur.insert(right[j]);
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
}