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
const int mod = 1e9 + 7, abc = 864197532, N = 300000, logN = 18, M = 2e7;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), nxt(n, n + 1), pre(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i], --a[i];
        if (~pre[a[i]]) nxt[pre[a[i]]] = i;
        pre[a[i]] = i;
    }
    vector <int> now(2, -1);
    int ans = 1;
    now[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (now[1] == -1) {
            if (a[0] == a[i]) now[0] = i;
            else now[1] = i, ans++;
        } else if (a[now[0]] == a[i]) {
            now[0] = i;
        } else if (a[now[1]] == a[i]) {
            now[1] = i;
        } else {
            ans++;
            if (nxt[now[0]] > nxt[now[1]]) {
                now[0] = i;
            } else {
                now[1] = i;
            }
        }
    }
    cout << ans << endl;
}