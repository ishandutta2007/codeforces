#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
pii a[maxn];
int p[maxn];
int dp[maxn];
int ans[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        dp[i] = inf;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 3; j <= 10 && j <= i; j++) {
            int cur = dp[i-j] + a[i].first - a[i-j+1].first;
            if(cur < dp[i]) {
                dp[i] = cur;
                p[i] = i - j;
            }
        }
    }
    int cur = 0;
    for(int i = n; i > 0; i = p[i]) {
        cur++;
        for(int j = i; j > p[i]; j--) {
            ans[a[j].second] = cur;
        }
    }
    cout << dp[n] << " "<<*max_element(ans + 1, ans + n + 1) << "\n";
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}