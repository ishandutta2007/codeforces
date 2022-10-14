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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    lli t;
    string s;
    cin >> n >> t >> s;
    vector <lli> cnt(27, 0);
    lli al = 0;
    for (int i = 0; i < n - 2; ++i) cnt[s[i] - 'a']++, al += 1 << s[i] - 'a';
    t -= (1 << s[n - 1] - 'a');
    t += (1 << s[n - 2] - 'a');
    if (-al > t || t > al) {
        cout << "NO\n";
        return 0;
    }
    t += al;
    if (t & 1) {
        cout << "NO\n";
        return 0;
    }
    t >>= 1;
    for (int i = 0; i < 26; ++i) {
        if (t & (1 << i)) {
            if (cnt[i] == 0) {
                cout << "NO\n";
                return 0;
            }
            cnt[i]--;
        }
        cnt[i + 1] += cnt[i] * 2;
    }
    cout << "YES\n";
}