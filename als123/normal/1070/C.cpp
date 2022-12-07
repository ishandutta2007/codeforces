#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn=1e6+7;

int n,m,k,cnt;
LL ans;

struct rec{
	LL sum,num;
}t[maxn*4];

struct ope{
	LL t,v,x;
}q[maxn*2];

bool cmp(ope a,ope b)
{
	return a.t<b.t;
}

rec merge(rec a,rec b)
{
	return (rec){a.sum+b.sum,a.num+b.num};
}

void updata(int p,int l,int r,int x,int k)
{
	if (l==r)
	{
		t[p].num+=(LL)k;
		t[p].sum+=(LL)x*(LL)k;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) updata(p*2,l,mid,x,k);
		   else updata(p*2+1,mid+1,r,x,k);
	t[p]=merge(t[p*2],t[p*2+1]);
}

LL query(int p,int l,int r,int k)
{
	if (l==r)
	{
		if (k>=t[p].num) return t[p].sum;	 
		return (LL)k*(LL)l;
	}
	int mid=(l+r)/2;
	if (t[p*2].num<k) return query(p*2+1,mid+1,r,k-t[p*2].num)+t[p*2].sum;
	return query(p*2,l,mid,k);
}

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1;i<=m;i++)
	{
		int L,R,A,B;
		scanf("%d%d%d%d",&L,&R,&A,&B);
		q[++cnt]=(ope){L,A,B};
		if (R!=n) q[++cnt]=(ope){R+1,-A,B};
	}
	sort(q+1,q+cnt+1,cmp);
	int j=1;
	for (int i=1;i<=n;i++)
	{
		while ((j<=cnt) && (q[j].t==i))
		{
			updata(1,1,1e6,q[j].x,q[j].v);
			j++;
		}
		ans+=query(1,1,1e6,k);
	}
	printf("%lld\n",ans);
}