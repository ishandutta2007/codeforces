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
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    deque <int> dq(a, a + n);
    int now = -1;
    string ans;
    while (!dq.empty()) {
        if (dq.front() < dq.back()) {
            if (now < dq.front()) {
                now = dq.front();
                dq.pop_front();
                ans.pb('L');
            } else if (now < dq.back()) {
                now = dq.back();
                dq.pop_back();
                ans.pb('R');
            } else {
                break;
            }
        } else {
            if (now < dq.back()) {
                now = dq.back();
                dq.pop_back();
                ans.pb('R');
            } else if (now < dq.front()) {
                now = dq.front();
                dq.pop_front();
                ans.pb('L');
            } else {
                break;
            }
        }
    }
    cout << ans.length() << endl;
    cout << ans << endl;
}