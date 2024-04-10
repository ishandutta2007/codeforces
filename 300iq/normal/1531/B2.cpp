#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map <pair <int, int>, int> mp;
    map <int, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        if (w > h) swap(w, h);
        if (w == h) {
            ans += cnt[w];
            cnt[w]++;
        } else {
            ans += cnt[w] + cnt[h] - mp[{w, h}];
            cnt[w]++, cnt[h]++;
            mp[{w, h}]++;
        }
    }
    cout << ans << endl;
}