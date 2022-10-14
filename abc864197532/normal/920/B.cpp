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
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 201, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> l(n), r(n);
        for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
        queue <int> q;
        vector <int> ans(n, 0);
        int now = 0;
        for (int time = 0; time <= 7000; ++time) {
            while (now < n && l[now] == time) q.push(now++);
            while (!q.empty() && r[q.front()] < time) q.pop();
            if (!q.empty()) ans[q.front()] = time, q.pop();
        }
        printv(ans);
    }
}