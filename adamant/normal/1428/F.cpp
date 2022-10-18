#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1e6;
int cnt[maxn];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int sum = 0;
    int streak = 0;
    for(auto c: s) {
        if(c == '1') {
            streak++;
            cnt[streak] += cnt[streak - 1];
            sum += cnt[streak - 1];
            cnt[streak - 1] = 0;
            ans += sum + streak * (streak + 1) / 2;
        } else {
            for(int i = 0; i <= streak; i++) {
                cnt[i]++;
                sum += i;
            }
            ans += sum;
            streak = 0;
        }
    }
    cout << ans << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
}