#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, k;
ll a[maxn];
ll b[maxn];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= (i + 1);
        a[i] *= (n - i);
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    reverse(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        a[i] %= mod;
        ans = (ans + a[i] * b[i]) % mod;
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