#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
ll x, y;
int a[maxn];
int b[maxn];
int c[maxn];
vector<int> p;
void add(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            while(x % i == 0) {
                x/=i;
            }
            p.emplace_back(i);
        }
    }

    if(x>1)p.emplace_back(x);
}
ll ans;
ll dp[maxn][3];
void calc(int pr) {
    for(int i = 0; i < n; i++) {
        if(a[i] % pr == 0) b[i + 1] = 1;
        else b[i+1] = 0;
        c[i+1] = 0;
        for(int j = -1; j < 2; j++) {
            if((a[i]+j) % pr == 0) c[i + 1] = 1;
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j] = 1ll<<61;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][1]) + x);
        if(b[i]) {
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
            dp[i][2] = min(dp[i][2], min(dp[i-1][1], dp[i-1][2]));
        }
        if(c[i]) {
            dp[i][0] = min(dp[i][0], dp[i-1][0] + y);
            dp[i][2] = min(dp[i][2], min(dp[i-1][1], dp[i-1][2]) + y);
        }
    }
    for(int i = 0; i < 3; i++) {
        ans = min(ans, dp[n][i]);
    }

}
void solve(){
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i =-1; i <= 1; i++) {
        add(a[0] + i);
        add(a[n-1] + i);
    }
    ans = (n-1ll) * x;
    sort(p.begin(), p.end());
    for(int i = 0; i < p.size(); i++) {
        if(i == 0 || p[i] != p[i-1]) calc(p[i]);
    }
    cout << ans << "\n";
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