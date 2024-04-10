#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)75*1000+10)
#define SQ ((ll)400)
#define QS ((ll)N/SQ+10)
#define K ((ll)200*1000+10)

struct Function
{
	int x1,x2,y1,a,b,y2;
};

int n,q;
ll res[QS][K],out[QS],ex[K];
Function a[N];

void build(ll x)
{
	int l=x*SQ,r=min((ll)n,(x+1)*SQ);
	for(int i=l;i<r;i++)
		ex[a[i].x1+1]+=a[i].b,ex[a[i].x2+1]+=a[i].y2-a[i].b;
	for(int i=0;i<K;i++)
	{
		res[x][i]+=ex[i];
		if(i<K-1)ex[i+1]+=ex[i];
		ex[i]=0;
	}
	for(int i=l;i<r;i++)
		ex[a[i].x1]+=a[i].y1;
	for(int i=K-1;i>=0;i--)
	{
		res[x][i]+=ex[i];
		if(i>0)ex[i-1]+=ex[i];
		ex[i]=0;
	}
	for(int i=l;i<r;i++)
		ex[a[i].x1+1]+=a[i].a,ex[a[i].x2+1]-=a[i].a;
	for(int i=0;i<K;i++)
	{
		res[x][i]+=ex[i]*i;
		if(i<K-1)ex[i+1]+=ex[i];
		ex[i]=0;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d%d%d",&a[i].x1,&a[i].x2,&a[i].y1,&a[i].a,&a[i].b,&a[i].y2),
		out[i/SQ]+=a[i].y2;
	for(int i=0;i<(n+SQ-1)/SQ;i++)
		build(i);
	scanf("%d",&q);
	ll lst=0;
	while(q--)
	{
		int l,r,x;
		ll ans=0;
		scanf("%d%d%d",&l,&r,&x);l--;
		x=((1LL*x+lst)%((ll)1e9));
		while(l%SQ && l<r)
		{
			if(x>a[l].x2)ans+=a[l].y2;
			else if(x>a[l].x1)ans+=1LL*a[l].a*x+a[l].b;
			else ans+=a[l].y1;
			l++;
		}
		while(r%SQ && l<r)
		{
			r--;
			if(x>a[r].x2)ans+=a[r].y2;
			else if(x>a[r].x1)ans+=1LL*a[r].a*x+a[r].b;
			else ans+=a[r].y1;
		}
		l/=SQ,r/=SQ;
		for(int i=l;i<r;i++)
		{
			if(x>=K)ans+=out[i];
			else ans+=res[i][x];
		}
		lst=ans;
		printf("%I64d\n",ans);
	}
	return 0;
}