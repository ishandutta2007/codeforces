#include<bits/stdc++.h>
using namespace std;
char s[100009];
int a[1009][1009],b[1009][1009],u[3],v[3],n,w[3];
int get(int x){
	return ((x-1)%n+n)%n+1;
}
int main(){
	int T,m,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",a[i]+j);
		u[0]=u[1]=u[2]=0,v[0]=0,v[1]=1,v[2]=2;
		scanf("%s",s);
		for(i=0;i<m;++i){
			if(s[i]=='R')++u[v[1]];
			else if(s[i]=='L')--u[v[1]];
			else if(s[i]=='D')++u[v[0]];
			else if(s[i]=='U')--u[v[0]];
			else if(s[i]=='I')swap(v[1],v[2]);
			else if(s[i]=='C')swap(v[0],v[2]);
		}
		u[0]=((u[0]-1)%n+n)%n+1;
		u[1]=((u[1]-1)%n+n)%n+1;
		u[2]=((u[2]-1)%n+n)%n+1;
		for(i=1;i<=n;++i)for(j=1;j<=n;++j){
			w[0]=get(i+u[0]),w[1]=get(j+u[1]),w[2]=get(a[i][j]+u[2]);
			b[w[v[0]]][w[v[1]]]=w[v[2]];
		}
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j)printf("%d ",b[i][j]);
			putchar(10);
		}
		putchar(10);
	}
	return 0;
}