#include<cstdio>
#include<cstring>
#include<vector>
#define LL long long
#define mod 998244353
using namespace std;
int n,m;
int c[1000002],arr[1002]={},R[502];
LL f[1002][1002];
vector<int> vec[502];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int x,int d)
{
	while(x<=m)arr[x]+=d,x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)res+=arr[x],x-=lowbit(x);
	return res;
}
inline LL calc(int l,int r)
{
	if(l>r)return 1;
	if(~f[l][r])return f[l][r];
	int mn=l,mn1=l,la;LL res1=0,res2=0,res3=1;
	for(int i=l+1;i<=r;++i)
	{
		if(c[i]<c[mn])mn=mn1=i;
		else if(c[i]==c[mn])mn1=i;
	}
	la=mn;
	for(int i=l+1;i<=r;++i)
		if(c[i]==c[mn] && i>la)
			res3=(res3*calc(la+1,i-1))%mod,la=i;
	for(int i=l;i<=mn;i=R[c[i]]+1)res1=(res1+calc(l,i-1)*calc(i,mn-1))%mod;
	for(int i=mn1;i<=r;i=R[c[i+1]])res2=(res2+calc(mn1+1,i)*calc(i+1,r))%mod;
	return f[l][r]=(((res1*res2)%mod)*res3)%mod;
}
int main()
{
	memset(f,-1,sizeof(f)),scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&c[i]);
		if(c[i]>n)return 0&puts("0");
		if(c[i]==c[i-1])--i,--m;
		else R[c[i]]=i;
	}
	if(m>=2*n)return 0&puts("0");
	for(int i=1;i<=m;++i)vec[c[i]].push_back(i);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<vec[i].size();++j)modify(vec[i][j],1);
		if(vec[i].size()>=2 && query(vec[i].back())-query(vec[i][0]-1)!=vec[i].size())return 0&puts("0");
	}
	R[c[m+1]=0]=m+1;
	return 0&printf("%lld",calc(1,m));
}