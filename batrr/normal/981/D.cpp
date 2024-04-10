// Tima the best
#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/                       
#define ll long long   
#define ull unsigned long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,inf=1e9,mod=1e9+7;
ll dp[100][100],a[100],pre[100],n,k;
ll sum(int l,int r){
	return pre[r]-pre[l-1];
}
bool check(ll x){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			for(int q=1;q<=i;q++)
				if( dp[q-1][j-1] && (sum(q,i)&x)==x )
		        	dp[i][j]=1;	
	}
	return dp[n][k];
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("headmasters.in", "r", stdin);
	//	freopen ("headmasters.out", "w", stdout);
    #endif        
    cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    	pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    for(int i=60;i>=0;i--)
    	if( check( (1ll<<i)|ans) )
    		ans|=(1ll<<i);
    cout<<ans;
}