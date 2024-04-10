#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 998244353;
int cnt[200005];
int f[200005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= 200000; ++i) f[i] = f[i - 1] * i % mod;
    for (int i = 1; i <= n - 1; ++i){
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i){
        ans = ans * f[cnt[i]] % mod;
    }
    cout << ans * n % mod << '\n';
    return 0;
}