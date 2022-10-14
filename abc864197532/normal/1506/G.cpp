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

void solve() {
    string s;
    cin >> s;
    vector <bool> choose(26, false);
    while (!s.empty()) {
        int n = s.length();
        for (char c = 'z'; c >= 'a'; --c) {
            vector <int> cnt(26, 0);
            for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
            bool fail = false;
            int to = -1;
            for (int i = 0; i < n; ++i) {
                if (s[i] == c) {
                    to = i;
                    break;
                } else {
                    cnt[s[i] - 'a']--;
                    if (!cnt[s[i] - 'a']) {
                        fail = true;
                        break;
                    }
                }
            }
            if (fail) continue;
            cout << c;
            choose[c - 'a'] = true;
            string t;
            for (int i = to + 1; i < n; ++i) if (!choose[s[i] - 'a']) t.pb(s[i]);
            s = t;
            break;
        }
    }
    cout << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}