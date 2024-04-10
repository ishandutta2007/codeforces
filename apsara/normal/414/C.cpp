#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1101000;
const int P=1000000007;
LL rev[30][2];
int a[V];
int tr[V],N;
void update(int k,int v)
{
	while(k<=N)
	{
		tr[k]+=v;
		k+=k&-k;
	}
}
int read(int k)
{
	int ret=0;
	while(k>0)
	{
		ret+=tr[k];
		k-=k&-k;
	}
	return ret;
}
void init(int id,int l,int r,int d)
{
	if(l==r)return;
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++)
	update(a[i],1);
	for(int i=mid+1;i<=r;i++)
	rev[d][1]+=read(a[i]-1);
	for(int i=l;i<=mid;i++)
	update(a[i],-1);

	for(int i=r;i>mid;i--)
	update(a[i],1);
	for(int i=mid;i>=l;i--)
	rev[d][0]+=read(a[i]-1);
	for(int i=r;i>mid;i--)
	update(a[i],-1);
	init(id*2,l,mid,d+1);
	init(id*2+1,mid+1,r,d+1);
}
int r[V];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int st[40],n,Q,x;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=(1<<n);i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=(1<<n);i++)
		r[i]=i;
		sort(r+1,r+(1<<n)+1,cmp);
		N=1;
		int pre=a[r[1]];
		a[r[1]]=1;
		for(int i=2;i<=(1<<n);i++)
		{
			if(a[r[i]]!=pre)
			{
				pre=a[r[i]];
				N++;
			}
			a[r[i]]=N;
		}
		memset(rev,0,sizeof(rev));
		memset(st,0,sizeof(st));
		init(1,1,(1<<n),0);
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%d",&x);
			x=n-x;
			for(int i=x;i<=n;i++)st[i]^=1;
			LL ret=0;
			for(int i=0;i<=n;i++)
			ret+=rev[i][st[i]];
			printf("%I64d\n",ret);
		}
	}
}