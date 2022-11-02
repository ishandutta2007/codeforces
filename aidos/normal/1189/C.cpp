#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
int sum[maxn];
int a[maxn];
int n, q;
int val[18][maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = (sum[i-1] + a[i]);
    }
    for(int len = 1; (1<<len) <= n; len++) {
        for(int i = 1; i <= n; i++) {
            val[len][i] = val[len-1][i] + val[len-1][i+(1<<(len-1))];
            int x = (sum[i + (1<<len) - 1] - sum[i + (1<<(len-1)) - 1]) % 10;
            int y = (sum[i+(1<<(len-1)) - 1]-sum[i-1]) % 10;
            if(x+y>9) val[len][i]++;
        }
    }
    cin >> q;
    for(int i=0; i < q; i++) {
        int l, r;
        cin>>l >> r;
        int x = 0;
        while(l + (1<<x) <= r) x++;
        cout << val[x][l] << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}