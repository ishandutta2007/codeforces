#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int s0 = 0, s1 = 0;
    int mod = 1000000007;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        if (i%2 == 0) {
            k = s1+1;
            k %= mod;
            s0 += k;
            s0 %= mod;
        } else {
            k = s0+1;
            k %= mod;
            s1 += k;
            s1 %= mod;
        }
    }
    cout  << (s1+s0)%mod;
    return 0;
}