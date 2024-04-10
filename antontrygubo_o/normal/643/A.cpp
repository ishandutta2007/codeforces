#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int maxN = 5005;
int t[maxN], cnt[maxN];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof cnt);
        pair < int, int > best = make_pair(0, -1);
        for (int j = i; j <= n; j++) {
            cnt[t[j]]++;
            best = max(best, make_pair(cnt[t[j]], -t[j]));
            ans[-best.second]++;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}