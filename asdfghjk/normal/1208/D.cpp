#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200005;
int n,i,j,mnpt[N*5],p[N];
ll s[N],mn[N*5],add[N*5],w;
void built(int o,int l,int r)
{
	if(l==r)
	{
		mn[o]=s[l];
		mnpt[o]=l;
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	if(mn[o<<1|1]==mn[o])
		mnpt[o]=mnpt[o<<1|1];
	else
		mnpt[o]=mnpt[o<<1];
}
void pushdown(int o,int l,int r)
{
	add[o<<1]+=add[o],add[o<<1|1]+=add[o];
	mn[o<<1]+=add[o],mn[o<<1|1]+=add[o];
	add[o]=0;
}
void update(int o,int l,int r,int x,int y,ll z)
{
	if(l>=x&&r<=y)
	{
		mn[o]+=z;
		add[o]+=z;
		return;
	}
	pushdown(o,l,r);
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y,z);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	if(mn[o<<1|1]==mn[o])
		mnpt[o]=mnpt[o<<1|1];
	else
		mnpt[o]=mnpt[o<<1];
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%I64d",s+i);
	built(1,1,n);
	for(i=1;i<=n;++i)
	{
		j=mnpt[1],w=mn[1];
		p[j]=i;
		update(1,1,n,j,j,1ll<<60);
		if(j<n)
			update(1,1,n,j+1,n,-i);
	}
	for(i=1;i<=n;++i)
		printf("%d ",p[i]);
	return 0;
}