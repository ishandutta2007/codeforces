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
const int mod = 1e9 + 7, abc = 864197532, N = 200005, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i <= n - i - 1; ++i) {
        vector <int> cnt(128, 0);
        cnt[s[i]] ^= 1;
        cnt[t[i]] ^= 1;
        if (i != n - i - 1) {
            cnt[s[n - i - 1]] ^= 1;
            cnt[t[n - i - 1]] ^= 1;
        }
        if (accumulate(all(cnt), 0) == 0) {
            continue;
        }
        int add = 2;
        for (int c = 'a'; c <= 'z'; ++c) {
            cnt[s[i]] ^= 1;
            cnt[c] ^= 1;
            if (accumulate(all(cnt), 0) == 0) {
                add = 1;
            }
            cnt[c] ^= 1;
            cnt[s[i]] ^= 1;
        }
        for (int c = 'a'; c <= 'z'; ++c) {
            cnt[s[n - i - 1]] ^= 1;
            cnt[c] ^= 1;
            if (accumulate(all(cnt), 0) == 0) {
                add = 1;
            }
            cnt[c] ^= 1;
            cnt[s[n - i - 1]] ^= 1;
        }
        ans += add;
    }
    cout << ans << endl;
}