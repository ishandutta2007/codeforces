#include<bits/stdc++.h>
using namespace std;
const int N=1009;
char s[N][N];
bool b[21][21],c[21][21],d[21][21];
int px[N],py[N],c1,c2;
bool cov(int x,int y,int u,int v){
	int i;
	for(i=x;i<=u;++i){
		if(!b[i][y]||!b[i][v])return 0;
		c[i][y]=c[i][v]=1,c1+=2;
	}
	for(i=y+1;i<v;++i){
		if(!b[x][i]||!b[u][i])return 0;
		c[x][i]=c[u][i]=1,c1+=2;
	}
	return 1;
}
bool cov2(int x,int y,int u,int v){
	int i;
	for(i=x;i<=u;++i){
		if(!b[i][y]||!b[i][v])return 0;
		if(c[i][y])--c2;
		if(c[i][v])--c2;
		c2+=2;
	}
	for(i=y+1;i<v;++i){
		if(!b[x][i]||!b[u][i])return 0;
		if(c[x][i])--c2;
		if(c[u][i])--c2;
		c2+=2;
	}
	return 1;
}
int main(){
	int n0,m0,n=0,m=0,i,j,k,u,v,al=0,i2,j2,i3,j3,i4,j4;
	bool f;
	scanf("%d%d",&n0,&m0);
	for(i=1;i<=n0;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n0;++i){
		f=0;
		for(j=1;j<=m0;++j)if(s[i][j]=='#'){f=1;break;}
		if(!f)continue;
		f=0;
		if(i-2<1||i+3>n0)f=1;
		else for(j=i-2;j<=i+3;++j)if(i!=j)for(k=1;k<=m0;++k)if(s[i][k]!=s[j][k]){f=1;break;}
		if(!f)continue;
		px[++n]=i;
	}
	for(i=1;i<=m0;++i){
		f=0;
		for(j=1;j<=n0;++j)if(s[j][i]=='#'){f=1;break;}
		if(!f)continue;
		f=0;
		if(i-2<1||i+3>m0)f=1;
		else for(j=i-2;j<=i+3;++j)if(i!=j)for(k=1;k<=n0;++k)if(s[k][i]!=s[k][j]){f=1;break;}
		if(!f)continue;
		py[++m]=i;
	}
	if(n>19||m>19)puts("NO"),exit(0);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(s[px[i]][py[j]]=='#')b[i][j]=1,++al;
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(b[i][j]){
		for(i2=i+2;i2<=n;++i2)for(j2=j+2;j2<=m;++j2)if(b[i2][j2]){
			if(memset(c,0,sizeof c),c1=0,cov(i,j,i2,j2)){
				for(i3=1;i3<=n;++i3)for(j3=1;j3<=m;++j3)if(b[i3][j3]){
					for(i4=i3+2;i4<=n;++i4)for(j4=j3+2;j4<=m;++j4)if(b[i4][j4]){
						if(c2=0,cov2(i3,j3,i4,j4)){
							if(c1+c2==al){
								printf("YES\n%d %d %d %d\n%d %d %d %d",px[i],py[j],px[i2],py[j2],px[i3],py[j3],px[i4],py[j4]);
								exit(0);
							}
						}
					}
				}
			}
		}
		break;
	}
	puts("NO");
	return 0;
}