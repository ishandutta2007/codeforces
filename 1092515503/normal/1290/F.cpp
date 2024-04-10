#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[30][21][21][21][21][2][2],n,m,X[5],Y[5];
int dfs(int bit,int a,int b,int c,int d,bool x,bool y){
	if(bit==30)return !a&&!b&&!c&&!d&&!x&&!y;
	int&res=f[bit][a][b][c][d][x][y];
	if(res!=-1)return res;
	res=0;
	int A=a,B=b,C=c,D=d;
	bool xx=x,yy=y;
	for(int i=0;i<(1<<n);i++){
		a=A,b=B,c=C,d=D,x=xx,y=yy;
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			if(X[j]>0)a+=X[j];
			if(X[j]<0)b-=X[j];
			if(Y[j]>0)c+=Y[j];
			if(Y[j]<0)d-=Y[j];
		}
		if((a&1)>((m>>bit)&1))x=true;
		if((a&1)<((m>>bit)&1))x=false;
		if((c&1)>((m>>bit)&1))y=true;
		if((c&1)<((m>>bit)&1))y=false;
		if((a&1)!=(b&1))continue;
		if((c&1)!=(d&1))continue;
		a>>=1,b>>=1,c>>=1,d>>=1;
		(res+=dfs(bit+1,a,b,c,d,x,y))%=mod;
	}
//	printf("%d %d %d %d %d %d %d:%d\n",bit,A,B,C,D,xx,yy,res);
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d%d",&X[i],&Y[i]);
	memset(f,-1,sizeof(f));
	printf("%d\n",(dfs(0,0,0,0,0,false,false)+mod-1)%mod);
	return 0;
}