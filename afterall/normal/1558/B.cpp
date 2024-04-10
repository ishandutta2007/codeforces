#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=4e6+100;
int dp[N];
int pd[N];
ll par=0;
int bk[N];
int n,mod;
inline void maq(ll x,vector <int> a,int n){
    if (a.size()==0) {
        if (x>1){
            int z=n/x;
            int s=(n-1)/x;
            pd[n]-=dp[s];
            pd[n]+=dp[z]+mod;
            pd[n]%=mod;
        }
        return ;
    }
    int z=a.back();
    a.pop_back();
    while(n%x==0){
        maq(x,a,n);
        x*=z;
    }
}
int32_t main(){
    sync;
    for (int i=2;i<N;i++){
        if (bk[i]==0){
            for (int j=i;j<N;j+=i){
                bk[j]=i;
            }
        }
    }
    cin >> n >> mod;
    dp[1]=1;
    par=1;
    for (int i=2;i<=n;i++){
        pd[i]=pd[i-1];
        vector <int> a;
        vector <int> maq;
        maq.pb(1);
        ll j=i;
        ll s=1;
        while(j!=1){
        ll d=maq.size();
            s=1;
            ll z=bk[j];
            while(j%z==0){
                j/=z;
                s*=z;

                for (int k=0;k<d;k++){
                    maq.pb(maq[k]*s);
                }
            }
        }
        for (int k=1;k<maq.size();k++){
            ll x=maq[k];
           // cout << i << " " << x << endl;
            int zz=i/x;
            int ss=(i-1)/x;
            pd[i]-=dp[ss];
            pd[i]+=dp[zz]+mod;
            pd[i]%=mod;
        }
        dp[i]=par+pd[i];
        if (dp[i]>mod) dp[i]-=mod;
        par+=dp[i];
        par%=mod;
    }
    cout << dp[n] << endl;
}