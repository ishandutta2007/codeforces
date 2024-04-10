#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=5e3+10;
//ll dp[N][N];
int P[N][N];
int n,mod;
ll power(int n,int k){
    if (n<0) return 0;
    if (n<N && k<N){

        return P[n][k];
    }
    if (k==0){
        return 1;
    }
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
int fac[N*3];
int fm[N*3];
int ent(ll k,ll n){
    if (k<0 || k>n) return 0;
    if (k==0 || k==n) return 1;
    return 1ll * fac[n]*fm[k]%mod*fm[n-k]%mod;
}
int32_t main(){
    sync;
    cin >> n >> mod;
    for (int i=1;i<N;i++){
        P[i][0]=1;
        for (int j=1;j<N;j++){
            P[i][j]=1ll * P[i][j-1]*i%mod;
        }
    }
   // kill(P[2][3]);
    fac[0]=fm[1]=1;
    for (int i=1;i<N;i++){
        fac[i]=1ll * fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
   // kill(P[2][3]);
    ll ans=0;
    /*
    dp[0][0]=1;
    for (int i=2;i<=n;i++){
        for (int j=1;j<i;j++){
            for (int k=1;k<i;k++){
                dp[i][j]+=dp[i-k-1][j-1]*fac[k+1]%mod*ent(k,i-1)%mod;
                dp[i][j]%=mod;
            }
        }
    }
    for (int i=0;i<n-1;i++){
        for (int j=1;j<=n;j++){
            ans+=power(n-i-j,i)*dp[n-i][j]%mod*power(n-1,j)%mod*ent(i,n)%mod;
            ans%=mod;
        }
      //  cout << i << " ans1 " << ans << endl;
    
    }
    cout << ans << endl;
    */
    ans=0;
    for (int i=0;i<n-1;i++){
        for (int j=1;j<=n;j++){
            ll z=ent(j-1,n-i-j-1);
            if (z==0) break;
            z*=ent(j,i+j);
            z%=mod;
           // if (i==2 && j==1) cout << z << " rkfn " << power(n-i-j,i) << " " << power(n-1,j) << endl;
            z=1ll * z*fac[n]%mod*power(n-i-j,i)%mod*power(n-1,j)%mod;
            z*=fm[i+j];
           // z%=mod;
            ans+=z;
            ans%=mod;
        }
     //   cout << i << " ans2 " << ans << endl;
    }
    cout << ans << endl;
    
}