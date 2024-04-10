#include<bits/stdc++.h>
#define N 1010
#define M 10010
using namespace std;
vector<int> g[N];
int x[M],y[M],z[M];
long long dis[N];
bool del[N];
void sp(int num,int s,int n){
	memset(dis,0x3f,sizeof(dis));
	memset(del,0,sizeof(del));
	dis[s]=0;
	for(int i=0;i<n-1;i++){
		int mn=-1;
		for(int j=0;j<n;j++){
			if(del[j]) continue;
			if(mn<0||dis[j]<dis[mn]) mn=j;
		}
		del[mn]=true;
		for(int j=0;j<g[mn].size();j++){
			int u=g[mn][j];
			if(!z[u]&&u>=num) continue;
			if(dis[mn]+(z[u]?z[u]:1)<dis[mn^x[u]]) dis[mn^x[u]]=dis[mn]+(z[u]?z[u]:1);
		}
	}
}
int main(){
	int n,m,L,s,t;
	bool can=false;
	scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
		x[i]^=y[i];
	}
	int l=0,r=m+1;
	while(l+1<r){
		sp((l+r)/2,s,n);
		if(dis[t]>L) l=(l+r)/2;
		else r=(l+r)/2;
	}
	sp(0,s,n);
	if(l==m){
		puts("NO");
	}
	else if(dis[t]<L){
		puts("NO");
	}
	else if(dis[t]==L){
		puts("YES");
		for(int i=0;i<m;i++){
			printf("%d %d %d\n",x[i]^y[i],y[i],z[i]?z[i]:L+1);
		}
	}
	else{
		puts("YES");
		sp(l+1,s,n);
		for(int i=0;i<m;i++){
			if(!z[i]){
				if(i<l) z[i]=1;
				else if(i==l) z[i]=1+L-dis[t];
				else z[i]=L+1;
			}
			printf("%d %d %d\n",x[i]^y[i],y[i],z[i]);
		}
	}
	return 0;
}