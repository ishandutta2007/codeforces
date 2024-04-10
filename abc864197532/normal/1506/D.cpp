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
        int id = -1, p = 0;
        vector <int> a(n);
        map <int, int> m1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            m1[a[i]]++;
        }
        priority_queue <pii> pq;
        for (pii a : m1) {
            pq.emplace(a.Y, a.X);
        }
        int ans = n;
        while (pq.size() > 1) {
            int f1, v1, f2, v2;
            tie(f1, v1) = pq.top(); pq.pop();
            tie(f2, v2) = pq.top(); pq.pop();
            ans -= 2;
            f1--, f2--;
            if (f1) pq.emplace(f1, v1);
            if (f2) pq.emplace(f2, v2);
        }
        cout << ans << endl;
    }
}