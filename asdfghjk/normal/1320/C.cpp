#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int N=200005;
int n,m,p,id1[N],id2[N],id3[N],a[N],ca[N],b[N],cb[N],x[N],y[N],z[N],mx[N*5],add[N*5],ans,i,j,lt,rt,mid;
bool cmp1(int i,int j)
{
	return a[i]<a[j];
}
bool cmp2(int i,int j)
{
	return b[i]<b[j];
}
bool cmp3(int i,int j)
{
	return x[i]<x[j];
}
void built(int o,int l,int r)
{
	if(l==r)
	{
		mx[o]=-cb[id2[l]];
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void pushdown(int o,int l,int r)
{
	add[o<<1]+=add[o],add[o<<1|1]+=add[o];
	mx[o<<1]+=add[o],mx[o<<1|1]+=add[o];
	add[o]=0;
}
void update(int o,int l,int r,int x,int y,int z)
{
	if(l>=x&&r<=y)
	{
		add[o]+=z;
		mx[o]+=z;
		return;
	}
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(x<=mid)
		update(o<<1,l,mid,x,y,z);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",a+i,ca+i);
		id1[i]=i;
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",b+i,cb+i);
		id2[i]=i;
	}
	for(i=1;i<=p;++i)
	{
		scanf("%d%d%d",x+i,y+i,z+i);
		id3[i]=i;
	}
	sort(id1+1,id1+1+n,cmp1);
	sort(id2+1,id2+1+m,cmp2);
	sort(id3+1,id3+1+p,cmp3);
	built(1,1,m);
	ans=-ca[id1[1]]-cb[id2[1]];
	for(i=j=1;i<=n;++i)
	{
		while(j<=p&&a[id1[i]]>x[id3[j]])
		{
			if(y[id3[j]]<b[id2[m]])
			{
				lt=1,rt=m;
				while(lt<rt)
				{
					mid=lt+rt>>1;
					if(y[id3[j]]<b[id2[mid]])
						rt=mid;
					else
						lt=mid+1;
				}
				update(1,1,m,lt,m,z[id3[j]]);
			}
			++j;
		}
		ans=max(ans,mx[1]-ca[id1[i]]);
	}
	printf("%d",ans);
	return 0;
}