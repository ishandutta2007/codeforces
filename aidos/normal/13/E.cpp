#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)5e5 + 10;
const int K = 450;
int a[maxn];
int dp[maxn];
int cnt[maxn];
int n, m;
void calc(int id) {
    int l = id * K;
    int r = min(l + K - 1, n - 1);
    for(int i = r; i >= l; i--) {
        int c = a[i] + i;
        if(c > r) {
            dp[i] = i;
            cnt[i] = 0;
        } else {
            dp[i] = dp[c];
            cnt[i] = cnt[c]+1;
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <= (n-1)/K; i++) {
        calc(i);
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int x, y;
            cin >> x >> y;
            a[x-1] = y;
            calc((x-1)/K);
        }
        else {
            int x;
            cin >> x;
            x--;
            int pos=x;
            int c = 0;
            while(x < n) {
                c += cnt[x] + 1;
                x = dp[x];
                pos = x;
                x += a[x];
            }
            cout << pos+1 << " " << c << "\n";
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}