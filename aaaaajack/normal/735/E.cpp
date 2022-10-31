#include<bits/stdc++.h>
#define N 110
#define K 22
#define Q 1000000007
using namespace std;
long long dp[N][K][K];
//[node][closest black][furthest non-black+1]
vector<int> g[N];
void merge(long long a[K][K],long long b[K][K],long long c[K][K],int k){
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			c[i][j]=0;
		}
	}
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			for(int x=0;x<=k;x++){
				for(int y=0;y<=k;y++){
					int tmp=0;
					if(j+x>k) tmp=max(tmp,j);
					if(i+y>k) tmp=max(tmp,y+1);
					c[min(i,x+1)][tmp]+=a[i][j]*b[x][y]%Q;
				}
			}
		}
	}
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			c[i][j]%=Q;
		}
	}
}
void DFS(int u,int p,int k){
	dp[u][0][0]=1;
	dp[u][k][1]=1; //If no black, assume closest=k. Won't help any subtree anyway. 
	long long tmp[K][K];
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v!=p){
			DFS(v,u,k);
			merge(dp[u],dp[v],tmp,k);
			for(int j=0;j<=k;j++){
				for(int l=0;l<=k;l++){
					dp[u][j][l]=tmp[j][l];
				}
			}
		}
	}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	long long ans=0;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,0,k);
	for(int i=0;i<=k;i++) ans+=dp[1][i][0];
	printf("%lld\n",ans%Q);
	return 0;
}