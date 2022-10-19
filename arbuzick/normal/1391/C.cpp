#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 1;
    int mod = 1000000007;
    for(int i = 1; i <= n; ++i)
        ans = ans*i%mod;
    int ans2 = 1;
    for(int i = 0; i < n-1; ++i)
        ans2 = ans2*2%mod;
    cout << ((ans-ans2)%mod+mod)%mod;
    return 0;
}