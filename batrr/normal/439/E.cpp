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
int q,s,n;
int dp[maxn],f[maxn],rf[maxn];
int c(int k,int n){
    if(k<0 || k>n)
		return 0;
    return 1ll*f[n]*rf[k]%mod*rf[n-k]%mod;
}
int binpow(ll n,ll p){
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
 		f[i]=1ll*f[i-1]*i%mod;
	rf[maxn-1]=binpow(f[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)
		rf[i]=1ll*rf[i+1]*(i+1)%mod;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&s,&n);
        vector<int>d;
		for(int i=1;i*i<=s;i++){
			if(s%i==0){ 
				d.pb(i);
				if(i*i!=s)
					d.pb(s/i);
			}
		}
		sort(d.begin(),d.end());
		for(int i=d.size()-1;i>=0;i--){
			dp[i]=c(n-1,s/d[i]-1);
			for(int j=i+1;j<d.size();j++)
				if( d[j]%d[i]==0 ){
					dp[i]-=dp[j];
					if(dp[i]<0)
						dp[i]+=mod;
				}                  
        }
        printf("%d\n",dp[0]);
	}
}