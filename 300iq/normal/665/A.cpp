#include <bits/stdc++.h>

using namespace std;

int main() {
    int ta, tb, a, b, h, m, l, r;
    char c;
    cin >> a >> ta;
    cin >> b >> tb;
    cin >> h >> c >> m;
    l = h * 60 + m;
    r = h * 60 + m + ta - 1;
    int auto_l = 5 * 60;
    int ans = 0;
    for (int auto_r = 5 * 60; auto_r <= 23 * 60 + 59; auto_r += b) {
        int cur_l = auto_r;
        int cur_r = auto_r + tb - 1;
        if (max(cur_l, l) <= min(cur_r, r)) {
            ans++;
        }
    }
    cout << ans << endl;
}