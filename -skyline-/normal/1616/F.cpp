//by dwq
#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("Ofast")
using namespace std;
int T,n,m,f[66][66],d[260],N;
int a[5300][260],A[260];
const int F[12]={0,1,2,0,1,2,0,1,2,0,1,2};
int main(){
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i){
			int x,y;
			scanf("%d%d%d",&x,&y,d+i);
			f[x][y]=f[y][x]=i;
			for(int j=1;j<=n;++j)if(j!=x&&j!=y&&f[j][x]&&f[j][y]){
				++N;
				a[N][i]=1;
				a[N][f[j][x]]=1;
				a[N][f[j][y]]=1;
			}
			if(d[i]!=-1){
				++N;
				a[N][i]=1;
				a[N][m+1]=d[i]%3;
			}
		}
		int k=0;
		for(int i=1;i<=m;++i){
			int o=0;
			for(int j=k+1;j<=N;++j)if(a[j][i])o=j,j=N+1;
			if(!o){
				d[i]=0;
				continue;
			}
			++k;
			A[k]=i;
			if(o!=k){
				for(int j=i;j<=m+1;++j)swap(a[o][j],a[k][j]);
			}
			if(a[k][i]==2){
				for(int j=i;j<=m+1;++j)a[k][j]=a[k][j]*2%3;
			}
			for(int j=1;j<=N;++j){
				if(j!=k&&a[j][i]){
					for(int _=m+1;_>i;--_)a[j][_]=F[a[j][_]-a[k][_]*a[j][i]+6];
					a[j][i]=0;
				}
			}
		}
		bool ok=1;
		for(int i=k+1;i<=N;++i)if(a[i][m+1])ok=0,i=N+1;
		if(!ok){
			while(N){
				for(int i=1;i<=m+1;++i)a[N][i]=0;
				--N;
			}
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=k;++i)d[A[i]]=a[i][m+1];
		for(int i=1;i<=m;++i)if(d[i]==-1)d[i]=0;
		for(int i=1;i<=m;++i)if(!d[i])d[i]=3;
		for(int i=1;i<m;++i)printf("%d ",d[i]);
		if(m)printf("%d\n",d[m]);
		while(N){
			for(int i=1;i<=m+1;++i)a[N][i]=0;
			--N;
		}
	}
    return 0;
}