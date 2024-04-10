#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+12,inf=1e9,LOG=18,mod=1e9+7;
ll n,m1,m2,a[maxn],was[maxn];
ll dp[maxn],f[maxn],rf[maxn];
ll c(int k,int n){
	if(k>n)
		return 0;
	return f[n]*rf[k]%mod*rf[n-k]%mod;
}
ll binpow(int n,int p){
	ll res=1,c=n;
	while(p){
		if(p&1)
			res=res*c%mod;
		c=c*c%mod;
		p/=2;
	}
	return res;
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    f[0]=1;
    for(int i=1;i<maxn;i++)
    	f[i]=f[i-1]*i%mod;
	rf[maxn-1]=binpow(f[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)
		rf[i]=rf[i+1]*(i+1)%mod;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=-1){
			was[i]=1;
			was[a[i]]=1;
		}else
			m2++;
		
    }
    for(int i=1;i<=n;i++)
    	if( !was[i] )
    		m1++;
    /*
    1 2 4 3 5

    */
	for(int k=n;k>=0;k--){
		if(m2-k>=0)
		dp[k]=c(k,m1)*f[m2-k]%mod;
		for(int j=k+1;j<=n;j++){
			dp[k]-=dp[j]*c(k,j)%mod;
			if(dp[k]<0)
				dp[k]+=mod;
		}
		//cout<<k<<" "<<dp[k]<<endl;
    }
    cout<<dp[0]<<endl;      
}