#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int MOD=1e9+7;

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    int ans=pow(3LL, 3*n, MOD) - pow(7LL, n, MOD);
    ans+=MOD;
    ans%=MOD;
    cout<<ans;
    return 0;   
}