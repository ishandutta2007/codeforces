#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int mod = 998244353;
int binpow(int x, int k){
    if(k == 0)
        return 1;
    if(k%2 == 1)
        return binpow(x, k-1)*x%mod;
    int a = binpow(x, k/2);
    return a*a%mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for(int i = 0; i < n; ++i)
        cin >> d[i];
    sort(all(d));
    vector<int> pr(n+1);
    for(int i = 0; i < n; ++i)
        pr[i+1] = pr[i]+d[i];
    while(m--){
        int a, b;
        cin >> a >> b;
        int pos = lower_bound(all(d), b)-d.begin();
        int cnt = n-pos;
        if(cnt < a){
            cout << 0 << '\n';
            continue;
        }
        int ans = (cnt-a)*binpow(cnt, mod-2)%mod*((pr[n]-pr[pos])%mod);
        ans += (cnt-a+1)*binpow(cnt+1, mod-2)%mod*((pr[pos]-pr[0])%mod);
        ans %= mod;
        cout << ans << '\n';
    }
    return 0;
}