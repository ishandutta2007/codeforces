#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6+123,inf=1e9+123,LOG=18,block=450,mod=1e9+7,N=1e6+123;
int n,m,k,s,a[2000][2000],q[maxn],dis[10][10],dp[2000][2000][10],ans;
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif                                     
	scanf("%d%d%d%d",&n,&m,&k,&s);
    for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);               
	
	for(int i=0;i<2000;i++)
		for(int j=0;j<2000;j++)
		    for(int x=1;x<=k;x++)
		    	dp[i][j][x]=-inf;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){                       
			for(int x=1;x<=k;x++){
				if( a[i][j]==x )
					dp[i][j][x]=0;
				if(i!=0)
					dp[i][j][x]=max(dp[i][j][x],dp[i-1][j][x]+1);
				if(j!=0)
					dp[i][j][x]=max(dp[i][j][x],dp[i][j-1][x]+1);
				int y=a[i][j];
				dis[x][y]=max(dis[x][y],dp[i][j][x]);
            }
		}
    }

	for(int i=0;i<n;i++)
		for(int j=0;j<m-j-1;j++)
			swap(a[i][j],a[i][m-j-1]);
    for(int i=0;i<2000;i++)
		for(int j=0;j<2000;j++)
		    for(int x=1;x<=k;x++)
		    	dp[i][j][x]=-inf;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){                       
			for(int x=1;x<=k;x++){
				if( a[i][j]==x )
					dp[i][j][x]=0;
				if(i!=0)
					dp[i][j][x]=max(dp[i][j][x],dp[i-1][j][x]+1);
				if(j!=0)
					dp[i][j][x]=max(dp[i][j][x],dp[i][j-1][x]+1);
				int y=a[i][j];
				dis[x][y]=max(dis[x][y],dp[i][j][x]);
            }
		}
    }

	for(int i=0;i<s;i++)         
		scanf("%d",&q[i]);
	for(int i=0;i+1<s;i++)
		ans=max(ans,dis[q[i]][q[i+1]]),
		ans=max(ans,dis[q[i+1]][q[i]]);
    cout<<ans;
}