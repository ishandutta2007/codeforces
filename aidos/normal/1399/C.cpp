#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, x;
int a[maxn];
void solve() {
    cin >> n;
    vector<int>cnt(n+1);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(int s = 0; s <= 2 * n; s++) {
        int cur = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                if(i + j == s) {
                    if (i == j) {
                        cur += cnt[i]/2;
                    }
                    else {
                        cur += min(cnt[i], cnt[j]);
                    }
                }
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}