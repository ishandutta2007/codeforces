#include<bits/stdc++.h>
#define N 210
using namespace std;
const int inf=123456789;
int d[N][N],c[N],ml[N],mr[N];
int ci,cj;
void upd(int &x,int y){
	if(y<x) x=y;
}
bool cmp(int a,int b){
	return d[a][ci]-d[a][cj]<d[b][ci]-d[b][cj];
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		fill(d[i]+1,d[i]+n+1,inf);
		d[i][i]=0;
		c[i]=i;
	}
	scanf("%d",&m);
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		scanf("%d",&d[x][y]);
		d[y][x]=d[x][y];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				upd(d[j][k],d[j][i]+d[i][k]);
			}
		}	
	}
	double ans=inf;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ci=i,cj=j;
			sort(c+1,c+n+1,cmp);
			ml[0]=mr[n+1]=0;
			for(int k=1;k<=n;k++){
				ml[k]=max(ml[k-1],d[i][c[k]]);
			}
			for(int k=n;k>=1;k--){
				mr[k]=max(mr[k+1],d[j][c[k]]);
			}
			double tans=inf;
			for(int k=1;k<n;k++){
				tans=min(tans,max(0.5*(ml[k]+mr[k+1]+d[i][j]),1.0*max(ml[k],mr[k+1])));
			}
			ans=min(ans,tans);
		}
	}
	printf("%g\n",ans);
	return 0;
}