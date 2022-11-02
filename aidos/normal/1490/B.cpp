#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)100200;
const ll inf = (1ll<<50);

int n;
int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}
void solve() {
    cin >> n;
    vector<int>cnt(3, 0);
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 3]++;
    }
    int ans = 0;
    for(int i = 0; i < 6; i++) {
        for (int i = 0; i < 3; i++) {
            if(cnt[(i + 1) % 3] < n/3) {
                int c = min(n/3 - cnt[(i + 1) % 3], cnt[i]);
                cnt[(i + 1) % 3] += c;
                cnt[i] -= c;
                ans += c;
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}