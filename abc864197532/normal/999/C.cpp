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
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector <int> v[26];
    for (int i = 0; i < n; ++i) v[s[i] - 'a'].pb(i);
    for (int i = 0; i < 26; ++i) {
        reverse(all(v[i]));
        while (k && !v[i].empty()) {
            v[i].pop_back();
            k--;
        }
    }
    vector <pair<int, char>> ans;
    for (int i = 0; i < 26; ++i) {
        while (!v[i].empty()) ans.eb(v[i].back(), i), v[i].pop_back();
    }
    sort(all(ans));
    for (auto a : ans) cout << char(a.Y + 'a');
}