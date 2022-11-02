#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, m, k;
int dp[maxn][202];
int a[maxn];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= 200; j++) {
        for(int i = n; i > 0; i--) {
            int t = i + j + a[i];
            if(t <= n) dp[i][j] = dp[t][j] + 1;
            else dp[i][j] = 1;
        }
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int p, k;
        cin >> p >> k;
        if(k <= 200) cout << dp[p][k] << "\n";
        else {
            int cnt = 0;
            while(p <= n) {
                p += a[p] + k;
                cnt++;
            }
            cout<<cnt<<"\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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