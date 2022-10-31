#include<bits/stdc++.h>
#define N 510
using namespace std;
int d[12][N][N];
int h[N][N],v[N][N];
inline void upd(int &x,int y){
	if(y<x) x=y;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			scanf("%d",&h[i][j]);
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&v[i][j]);
		}
	}
	for(int t=1;t<=k/2;t++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				d[t][i][j]=1e9;
				if(i) upd(d[t][i][j],d[t-1][i-1][j]+v[i-1][j]);
				if(i<n-1) upd(d[t][i][j],d[t-1][i+1][j]+v[i][j]);
				if(j) upd(d[t][i][j],d[t-1][i][j-1]+h[i][j-1]);
				if(j<m-1) upd(d[t][i][j],d[t-1][i][j+1]+h[i][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(k%2==0){
				printf("%d ",d[k/2][i][j]*2);
			}
			else printf("-1 ");
		}
		puts("");
	}
	return 0;
}