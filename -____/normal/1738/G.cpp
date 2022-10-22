#include<bits/stdc++.h>
using namespace std;
const int N = 1111;
int n,k,a[N][N],b[N][N],d[N];
char c[N];
int main(){
	int T,i,j,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		k--;
		for(i=1;i<=n;i++)
			d[i]=0;
		for(i=1;i<=n;i++){
			scanf("%s",c+1);
			for(j=1;j<=n;j++){
				a[i][j]=c[j]=='0';
				b[i][j]=0;
				if(abs(i-j)>=n-k)
					a[i][j]=1;
				if(abs(i-j)>n-k)
					b[i][j]=1;
				if(abs(i-j)<=n-k&&a[i][j])
					d[i]=max(d[i],j);
			}
		}
		for(i=k;i>=1;i--){
			x=i+n-k,y=i;
			b[x][y]=1;
			while(x-y>k-n){
				if(d[x]>y)
					y++;
				else
					x--;
				b[x][y]=1;
				while(d[x]&&(b[x][d[x]]||!a[x][d[x]])){
					d[x]--;
				}
			}
		}
		x=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(a[i][j]&&!b[i][j])
					x=1;
		if(x){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				printf("%d",b[i][j]);
			printf("\n");
		}
	}
	return 0;
}