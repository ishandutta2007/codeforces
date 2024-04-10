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
int a[maxn];
void solve() {
    cin >> n;
    int sum = 0, sum1 = 0, sum2 = 0, ans = -inf;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ans=sum;
    for(int i = 1; i <= n; i++) {
        sum1 += a[i];
        sum2 = max(sum2 + a[i], -sum1);
        ans = max(ans, sum1 - sum + sum2);
    }
    cout << ans << "\n";
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