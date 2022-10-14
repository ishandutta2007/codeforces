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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

vector <int> get(string s, string t) {
    vector <int> pre(s.length() + 1, 0);
    for (int i = 1; i <= s.length(); ++i) {
        if (pre[i - 1] == t.length()) pre[i] = pre[i - 1];
        else pre[i] = pre[i - 1] + (s[i - 1] == t[pre[i - 1]]);
    }
    return pre;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector <int> pre = get(s, t);
    reverse(all(s));
    reverse(all(t));
    vector <int> suf = get(s, t);
    reverse(all(suf));
    int ans = 0;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= n && pre[i] + suf[j] >= m) j++;
        j--;
        if (j <= n && pre[i] + suf[j] == m && pre[i] && suf[j]) {
            ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
}