#include <bits/stdc++.h>
using namespace std;
int n,m,K;
int a[1005][1005];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
		}
	}
	int x,y;
	while(K--){
		x=1;
		scanf("%d",&y);
		while(x<=n){
			if(a[x][y]==1){
				a[x][y]=2;
				++y;
			}
			else if(a[x][y]==2){
				++x;
			}
			else{
				a[x][y]=2;
				--y;
			}
		}
		printf("%d ",y);
	}
	puts("");
	return 0; 
}