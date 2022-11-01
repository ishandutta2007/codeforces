#include <bits/stdc++.h>

using namespace std;

int n, x, cnt[101], ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        int y; cin >> y;
        cnt[y]++;
    }
    for(int i = 0; i < x; i++) if(cnt[i] == 0) ans++;
    ans += cnt[x];
    cout << ans;
}