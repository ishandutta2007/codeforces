#include<bits/stdc++.h>
using namespace std;
int n,q,sq,mx,T;
int a[300002],cnt[300002],bl[300002],to[300002];
int f[552][552],s[552][552];
vector<int> vec;
vector<int> v[300002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void clear()
{
	for(int i=0;i<vec.size();++i)cnt[vec[i]]=0;
	vec.clear();
}
inline void init()
{
	scanf("%d%d",&n,&q),sq=sqrt(n),T=(n-1)/sq+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),bl[i]=(i-1)/sq+1;
	for(int i=1,st,ed;i<=T;++i)
	{
		mx=0,clear();
		for(int j=i;j<=T;++j)
		{
			st=(j-1)*sq+1,ed=min(j*sq,n);
			for(int k=st;k<=ed;++k)
			{
				if(!cnt[a[k]])vec.push_back(a[k]);
				if(i==1)to[k]=cnt[a[k]],v[a[k]].push_back(k);
				++cnt[a[k]];
				if(cnt[a[k]]>cnt[mx])mx=a[k];
			}
			f[i][j]=mx,s[i][j]=cnt[mx];
		}
	}
}
inline int solve(int l,int r)
{
	clear();
	if(bl[l]==bl[r])
	{
		mx=0;
		for(int i=l;i<=r;++i)
		{
			if(!cnt[a[i]])vec.push_back(a[i]);
			++cnt[a[i]];
			if(cnt[a[i]]>mx)mx=cnt[a[i]];
		}
		return max(mx-(r-l+1-mx),1);
	}
	int st=bl[l]*sq,ed=(bl[r]-1)*sq+1,t;
	t=f[bl[l]+1][bl[r]-1],mx=s[bl[l]+1][bl[r]-1];
	for(int i=l;i<=st;++i)if(a[i]==t)++mx;
	for(int i=ed;i<=r;++i)if(a[i]==t)++mx;
	for(int i=l,j;i<=st;++i)
	{
		j=to[i]+mx;
		if(j>=v[a[i]].size() || v[a[i]][j]>r)continue;
		while(j+1<v[a[i]].size() && v[a[i]][j+1]<=r)++j;
		mx=j-to[i]+1;
	}
	for(int i=ed,j;i<=r;++i)
	{
		j=to[i]-mx;
		if(j<0 || v[a[i]][j]<l)continue;
		while(j-1>=0 && v[a[i]][j-1]>=l)++j;
		mx=to[i]-j+1;
	}
	return max(mx-(r-l+1-mx),1);
}
int main()
{
	init();
	for(int l,r;q--;)read(l),read(r),printf("%d\n",solve(l,r));
	return 0;
}