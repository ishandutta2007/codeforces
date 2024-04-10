#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int ans = 0;
        for (int s = 1; s <= 2 * n; s++) {
            int now = 0;
            for (int w1 = 1; w1 <= s / 2; w1++) {
                if (w1 * 2 == s) now += cnt[w1] / 2;
                else now += min(cnt[w1], cnt[s - w1]);
            }
            ans = max(ans, now);
        }
        cout << ans << "\n";
    }
    return 0;
}