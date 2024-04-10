#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17, K = 3e6;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    while (s.size() && s.back() == '0') s.pop_back();
    while (t.size() && t.back() == '0') t.pop_back();
    reverse(all(s));
    reverse(all(t));
    if (s.length() > t.length()) cout << '>';
    else if (s.length() < t.length()) cout << '<';
    else {
        int i;
        for (i = 0; i < s.length(); ++i) {
            if (s[i] > t[i]) cout << '>';
            else if (s[i] < t[i]) cout << '<';
            else continue;
            break;
        }
        if (i == s.length()) cout << '=';
    }
}