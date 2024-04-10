#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 1000;
    for (int i = 0; i < 1000000; ++i) {
        string t;
        int tmp = i;
        while (tmp) {
            t += '0' + tmp % 10;
            tmp /= 10;
        }
        while (t.size() < 6) t += '0';
        reverse(t.begin(), t.end());
        int a[2] = {0, 0};
        for (int i = 0; i < 6; ++i) a[i / 3] += (t[i] - '0');
        if (a[0] == a[1]) {
            int cnt = 0;
            for (int i = 0; i < 6; ++i) {
                if (s[i] != t[i]) cnt++;
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
}