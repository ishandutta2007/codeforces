#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f[55][2][2],num[55];
int dfs(int x,bool lim1,bool lim2){//lim1:reverse lim2:reverse and ~
	if(x>n-x+1)return 1;
	if(f[x][lim1][lim2]!=-1)return f[x][lim1][lim2];
	int res=0;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++){
		if(num[x]!=-1&&num[x]!=i)continue;
		if(num[n-x+1]!=-1&&num[n-x+1]!=j)continue;
		if(lim1&&j<i)continue;
		if(lim2&&!j<i)continue;
		if(x==n-x+1&&i!=j)continue;
		res+=dfs(x+1,lim1&&(i==j),lim2&&(i!=j));
	}
	return f[x][lim1][lim2]=res;
}
signed main(){
	memset(f,-1,sizeof(f)),memset(num,-1,sizeof(num));
	scanf("%lld%lld",&n,&m),m++;
	if(dfs(1,1,1)<m){puts("-1");return 0;}
	num[1]=0;
	for(int i=2;i<=n;i++){
		num[i]=0;
		memset(f,-1,sizeof(f));
		int tmp=dfs(1,1,1);
		if(tmp<m)m-=tmp,num[i]=1;
	}
	for(int i=1;i<=n;i++)printf("%lld",num[i]);
	return 0;
}