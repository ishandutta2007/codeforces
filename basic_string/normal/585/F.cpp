#include<bits/stdc++.h>
using namespace std;
enum{N=1003,D=53,M=N*D,P=(int)1e9+7};
char s[N],x[N],y[N];
int n,d,d2,o,c[M][10],f[M],q[M],a[D][M][2],p[D][2];
bool e[M];
void bd(){
	int i,j,k,x,y;
	for(i=0;x=0,i<n;++i)for(j=0,k=i;j<d&&k<n;++k,++j){
		if(!c[x][y=s[k]-48])if(c[x][y]=++o,j>d2)e[o]=1;
		x=c[x][y];
	}
	for(i=x=y=0;i<10;++i)if(c[0][i])q[++y]=c[0][i];
	while(x<y){
		i=q[++x],j=f[i];
		for(k=0;k<10;++k)if(c[i][k])f[q[++y]=c[i][k]]=c[j][k];
		else c[i][k]=c[j][k];
	}
}
int wk(char*s){
	int i,j,k,l,x;
	for(p[i=d][0]=p[d][1]=1;i;--i)p[i-1][0]=p[i][0]*10ll%P,p[i-1][1]=(p[i][1]+p[i][0]*(s[i-1]-48ll))%P;
	for(memset(a,0,sizeof a),a[0][0][1]=1,i=0;i<d;++i)
		for(x=s[i]-48,j=0;j<=o;++j)if(!e[j])for(k=0;k<10;++k)
			if((a[i+1][l=c[j][k]][0]+=a[i][j][0])%=P,k<x)(a[i+1][l][0]+=a[i][j][1])%=P;
			else if(k==x)(a[i+1][l][1]+=a[i][j][1])%=P;
	for(i=1,k=0;i<=d;++i)for(j=0;j<=o;++j)if(e[j])k=(k+a[i][j][0]*1ll*p[i][0]+a[i][j][1]*1ll*p[i][1])%P;
	return k;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i;
	for(cin>>s>>x>>y,n=strlen(s),d=strlen(x),i=d-1;x[i]==48;)x[i--]=57;
	--x[i],d2=d/2-2,bd(),cout<<(wk(y)-wk(x)+P)%P;
	return 0;
}