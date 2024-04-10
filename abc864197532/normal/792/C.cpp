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
const int mod = 1e9 + 7, abc = 864197532, N = 1001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int sum = 0;
    int n = s.length();
    vector <int> cnt[3];
    for (int i = 0; i < n; ++i) {
        (sum += s[i] - '0') %= 3;
        cnt[(s[i] - '0') % 3].pb(i);
    }
    vector <string> ans;
    if (sum == 0) {
        ans.pb(s);
    } else if (sum == 1) {
        if (cnt[1].size() >= 1) {
            string t;
            for (int i = 0; i < n; ++i) if (i != cnt[1].back()) t.pb(s[i]);
            reverse(all(t));
            while (t.size() > 1 && t.back() == '0') t.pop_back();
            reverse(all(t));
            ans.pb(t);
        }
        if (cnt[2].size() >= 2) {
            string t;
            for (int i = 0; i < n; ++i) if (i != cnt[2].back() && i != cnt[2][cnt[2].size() - 2]) t.pb(s[i]);
            reverse(all(t));
            while (t.size() > 1 && t.back() == '0') t.pop_back();
            reverse(all(t));
            ans.pb(t);
        }
    } else {
        if (cnt[2].size() >= 1) {
            string t;
            for (int i = 0; i < n; ++i) if (i != cnt[2].back()) t.pb(s[i]);
            reverse(all(t));
            while (t.size() > 1 && t.back() == '0') t.pop_back();
            reverse(all(t));
            ans.pb(t);
        }
        if (cnt[1].size() >= 2) {
            string t;
            for (int i = 0; i < n; ++i) if (i != cnt[1].back() && i != cnt[1][cnt[1].size() - 2]) t.pb(s[i]);
            reverse(all(t));
            while (t.size() > 1 && t.back() == '0') t.pop_back();
            reverse(all(t));
            ans.pb(t);
        }
    }
    string tans = *max_element(all(ans), [](string a, string b) {
        return a.length() < b.length();
    });
    if (tans.empty()) cout << -1 << endl;
    else cout << tans << endl;
}