#include<bits/stdc++.h>
#define Mx 16
#define MXN 100000
using namespace std;
int n,q,ans,p_t=0;
int a[100002],p[100002],to[100002],cnt[100002]={};
int R[100002][18];
bool u[100002]={};
vector<int> vec[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	for(int i=2;i<=MXN;++i)
		if(!u[i])
		{
			p[++p_t]=i,to[i]=p_t;
			for(int j=i;j<=MXN/i;++j)
				u[j*i]=1;
		}
	read(n),read(q);
	for(int i=1,x;i<=n;++i)
	{
		read(a[i]),x=a[i];
		for(int j=1;p[j]<=x/p[j];++j)
			if(!(x%p[j]))
			{
				vec[i].push_back(j);
				do x/=p[j];while(!(x%p[j]));
			}
		if(x>1)vec[i].push_back(to[x]);
	}
	for(int i=1,j=0,ok;i<=n;++i)
	{
		if(i>1)for(int k=0;k<vec[i-1].size();++k)cnt[vec[i-1][k]]=0;
		ok=1;
		while(j+1<=n)
		{
			for(int k=0;k<vec[j+1].size();++k)if(cnt[vec[j+1][k]]){ok=0;break;}
			if(!ok)break;++j;
			for(int k=0;k<vec[j].size();++k)cnt[vec[j][k]]=1;
		}
		R[i][0]=j;
	}
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			R[j][i]=R[min(R[j][i-1]+1,n)][i-1];
	for(int l,r;q--;)
	{
		scanf("%d%d",&l,&r),ans=0;
		for(int i=Mx;~i;--i)
			if(l<=n && R[l][i]<r)
				ans|=(1<<i),l=R[l][i]+1;
		if(l<=r)++ans;
		printf("%d\n",ans);
	}
	return 0;
}