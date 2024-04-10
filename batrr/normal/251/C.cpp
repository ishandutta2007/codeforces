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
const ll maxn=1e6+12,inf=1e9,LOG=18,mod=1e9+7,N=8*9*5*7*11*13;
ll a,b,k,dp[N+1223];
ll get(ll st,ll en){
	for(int i=0;i<=N;i++)
		dp[i]=1e9;
    dp[st]=0;
	for(int i=st;i<=en;i++){
		dp[i]=min(dp[i],dp[i-1]+1);
		for(int j=2;j<=k;j++)
			if(i%j==0)
				for(int q=1;q<j;q++)
					dp[i+q]=min(dp[i+q],dp[i]+1);
	}
	return dp[en];
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif
 	cin>>a>>b>>k;
 	if(a/N==b/N)
 		cout<<get(b%N,a%N);
    else
    	cout<<(a/N-b/N-1)*get(0,N)+get(b%N,N)+get(0,a%N);
}