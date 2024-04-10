#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,a[9][300009],q[300009];
int p[9999];
bool b[9999];
bool check(int x){
	memset(b,0,sizeof(b));
	register int i,j,k;
	for(i=1;i<=n;++i){
		k=0;
		for(j=1;j<=m;++j){
			if(a[j][i]>=x)k|=1<<(j-1);
		}
		b[k]=1,p[k]=i,q[i]=k;
	}
	for(i=(1<<m)-1;i;--i){
		if(!b[i])continue;
		for(j=1<<(m-1);j;j>>=1){
			if(i&j)b[i^j]=1,p[i^j]=p[i];
		}
	}
	for(i=1;i<=n;++i){
		if(b[q[i]^((1<<m)-1)]){
			u=i,v=p[q[i]^((1<<m)-1)];
			return 1;
		}
	}
	return 0;
}
int main(){
	register int i,j,L=0,R=1e9+7,M,S;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			scanf("%d",&a[j][i]);
		}
	}
	while(L<=R){
		M=L+R>>1;
		if(check(M))L=M+1,S=M;
		else R=M-1;
	}
	check(S);
	printf("%d %d\n",u,v);
	return 0;
}//