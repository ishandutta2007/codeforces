#include<bits/stdc++.h>
#define bs 233
#define LL long long
using namespace std;
int n,Mx,t=0;
LL res;
int one[262144];
LL ans[262144],Hs[262144];
LL f[22][262144],tmp[22][262144];
char s[22][22];
vector<int> vec[402];
unordered_map<LL,int> mp;
inline void dfs(int x,int y,int d,LL hs)
{
	if(x==n)
	{
		for(int i=res=0;i<Mx;++i)res+=((one[i]^one[Mx-1])&1? -1:1)*tmp[d][i];
		for(int i=0,x=mp[hs];i<vec[x].size();++i)ans[vec[x][i]]=res;
		return ;
	}
	for(int i=y;x+i<=n;++i)
		if(x+i==n || (x+(i<<1)<=n))
		{
			for(int j=0;j<Mx;++j)tmp[d+1][j]=tmp[d][j]*f[i][j];
			dfs(x+i,i,d+1,hs*bs+i);
		}
}
int main()
{
	scanf("%d",&n),Mx=(1<<n);
	for(int i=0;i<n;++i)scanf("%s",s[i]),tmp[i][1<<i]=1;
	for(int i=1;i<Mx;++i)
	{
		one[i]=one[i>>1]+(i&1);
		for(int j=0;j<n;++j)if((i>>j)&1)
		{
			f[one[i]][i]+=tmp[j][i];
			for(int k=0;k<n;++k)if(!((i>>k)&1) && s[j][k]^48)tmp[k][i^(1<<k)]+=tmp[j][i];
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<Mx;j<<=1)for(int k=0;k<Mx;k+=(j<<1))for(int l=0;l<j;++l)f[i][j+k+l]+=f[i][k+l];
	for(int i=0;i<Mx;++i)tmp[0][i]=1;
	for(int i=0;i<(Mx>>1);++i)
	{
		vec[0].clear();
		for(int j=0,k;j<n;j=k+1)
		{
			for(k=j;k<n && (i>>k)&1;++k);
			vec[0].push_back(k-j+1);
		}
		sort(vec[0].begin(),vec[0].end());
		for(int j=0;j<vec[0].size();++j)Hs[i]=Hs[i]*bs+vec[0][j];
		if(!mp.count(Hs[i]))mp[Hs[i]]=(++t);
		vec[mp[Hs[i]]].push_back(i);
	}
	dfs(0,1,0,0),Mx>>=1;
	for(int i=1;i<Mx;i<<=1)for(int j=0;j<Mx;j+=(i<<1))for(int k=0;k<i;++k)ans[j+k]-=ans[i+j+k];
	for(int i=0;i<Mx;++i)printf("%lld ",ans[i]);
	return 0;
}