#include<bits/stdc++.h>
using namespace std;
const int N = 111;
int n,a[N],f[2][2][N][N];
int solve(int i,int j,int x,int y){
	if(x<0||y<0){
		if(i==0)
			return 1;
		return -1;
	}
	if(f[i][j][x][y])
		return f[i][j][x][y];
	if(x==0&&y==0){
		if(j==0)
			return 1;
		return -1;
	}
	if(i==0)
		return f[i][j][x][y]=max(solve(i^1,j,x-1,y),solve(i^1,j^1,x,y-1));
	return f[i][j][x][y]=min(solve(i^1,j,x-1,y),solve(i^1,j,x,y-1));
}
int main(){
	int T,i,j,x,s;
	n=105;
	for(i=0;i<=n;i++)
		for(j=0;i+j<=n;j++)
			solve(0,0,i,j);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			if(x&1)
				s++;
		}
		if(f[0][0][n-s][s]>0)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}