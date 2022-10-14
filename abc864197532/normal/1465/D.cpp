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

lli get(string s, int x, int y) {
    lli ans = 0, z = 0, o = 0;
    for (char c : s) {
        if (c == '0') ans += o * y, z++;
        else ans += z * x, o++;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    lli pre[n + 1][2], x, y, al = 0;
    cin >> x >> y;
    /*
     * put 0 -> pre[1] * y + suf[1] * x
     * put 1 -> pre[0] * y + suf[0] * x
     */
    pre[0][0] = pre[0][1] = 0;
    for (int i = 0; i < n; ++i) pre[i + 1][0] = pre[i][0] + (s[i] == '0'), pre[i + 1][1] = pre[i][1] + (s[i] == '1'), al += (s[i] == '?');
    lli ans = 1ll << 60;
    {
        string t = s;
        for (char &c : t) if (c == '?') c = '1';
        lli tmp = get(t, x, y), cur = tmp, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                cur -= (pre[i + 1][0] + cnt) * x + (pre[n][0] - pre[i + 1][0]) * y;
                cnt++;
                cur += pre[i + 1][1] * y + (pre[n][1] - pre[i + 1][1] + al - cnt) * x;
                tmp = min(tmp, cur);
            }
        }
        ans = min(ans, tmp);
    }
    {
        string t = s;
        for (char &c : t) if (c == '?') c = '0';
        lli tmp = get(t, x, y), cur = tmp, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                cur -= (pre[i + 1][1] + cnt) * y + (pre[n][1] - pre[i + 1][1]) * x;
                cnt++;
                cur += pre[i + 1][0] * x + (pre[n][0] - pre[i + 1][0] + al - cnt) * y;
                tmp = min(tmp, cur);
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}