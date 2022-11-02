#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
ll sum[maxn];
ll L[maxn];
int lpos[maxn];
ll R[maxn];
int rpos[maxn];
ll calc(int l, int r) {
    return sum[r] - sum[l];
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = -(1ll<<60);
    for(int i=0; i <= n; i++) {
        L[i] = -(1ll<<60);
        R[i] = -(1ll<<60);
        for(int j = 0; j <= i; j++) {
            ll cur = calc(0, j) - calc(j, i);
            if(cur > L[i]) {
                L[i] = cur;
                lpos[i] = j;
            }
        }
        for(int j = i; j <= n; j++) {
            ll cur = calc(i, j) - calc(j, n);
            if(cur > R[i]) {
                R[i] = cur;
                rpos[i] = j;
            }
        }
        ans = max(ans, L[i] + R[i]);
    }
    for(int i = 0; i <= n; i++) {
        if(L[i] + R[i] == ans) {
            cout << lpos[i] << " "<<i << " " << rpos[i] << "\n";
            return;
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