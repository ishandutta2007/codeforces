#include<cstdio>
#define N 510
int v[N][N],h[N][N];
char s[N][N];
int main(){
	int r,c,r1,c1,r2,c2;
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			h[i][j]=h[i-1][j]+h[i][j-1]-h[i-1][j-1];
			v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
			if(s[i][j]=='.'&&s[i][j-1]=='.') h[i][j]++;
			if(s[i][j]=='.'&&s[i-1][j]=='.') v[i][j]++;
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int hc=h[r2][c2]-h[r2][c1]-h[r1-1][c2]+h[r1-1][c1];
		int vc=v[r2][c2]-v[r2][c1-1]-v[r1][c2]+v[r1][c1-1];
		printf("%d\n",hc+vc);
	}
	return 0;
}