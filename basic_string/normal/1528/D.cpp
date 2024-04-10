#include<bits/stdc++.h>
using namespace std;
const int N=609;
int nx[N],ct2[N],ct[N],mo[N*3];
bool vis[N];
long long d[N];
struct P{
	int b,c;
	bool operator<(P a)const{return b<a.b;}
}p[N][N],o[N][N];
int main(){
	int n,m,i,j,k,s,t,u,v;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)nx[i]=(i+1)%n;
	for(i=0;i<N*3;++i)mo[i]=i%n;
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&j,&k,&s);
		p[j][++ct2[j]]={k,s};
	}
	for(i=0;i<n;++i){
		sort(p[i]+1,p[i]+ct2[i]+1);
		for(j=1;j<=ct2[i];++j){
			for(k=1;k<=ct2[i];++k){
				if(p[i][j].c-p[i][k].c>mo[p[i][j].b-p[i][k].b+n])goto gg;
			}
			o[i][++ct[i]]=p[i][j];
			gg:;
		}
	}
	for(i=0;i<n;++i){
		memset(d,9,sizeof d),d[i]=0,memset(vis,0,sizeof vis);
		for(j=0;j<n;++j){
			k=n+1;
			for(s=0;s<n;++s)if(!vis[s]&&d[s]<d[k])k=s;
			vis[k]=1,u=d[k]%n;
			for(t=1,s=(u+o[k][1].b)%n,v=s;;){
				while(t<ct[k]&&mo[u+o[k][t+1].b]==s)++t;
				if(!vis[s]){
				d[s]=min(d[s],d[k]+o[k][t].c+mo[s-o[k][t].b-u+n+n]);
			}
				if(s=nx[s],s==v)break;
			}
		}
		for(j=0;j<n;++j)printf("%lld ",d[j]);puts("");
	}
	return 0;
}