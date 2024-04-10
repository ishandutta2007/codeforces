#include<bits/stdc++.h>
using namespace std;
int n,m,f[210][13000],lim,res;
pair<int,int>p[210];
pair<int,int>read(){
	long long x;
	scanf("%I64d",&x);
	pair<int,int>ret=make_pair(0,0);
	while(!(x%5))x/=5,ret.first++;
	while(!(x&1))x>>=1,ret.second++;
	return ret;
}
int main(){
	scanf("%d%d",&n,&m),memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)p[i]=read(),lim+=p[i].first;
	f[0][0]=0;
	for(int i=1;i<=n;i++)for(int j=min(i,m);j;j--)for(int k=lim;k>=p[i].first;k--)if(f[j-1][k-p[i].first]!=-1)f[j][k]=max(f[j][k],f[j-1][k-p[i].first]+p[i].second);
	for(int i=1;i<=lim;i++)res=max(res,min(i,f[m][i]));
	printf("%d\n",res);
	return 0;
}