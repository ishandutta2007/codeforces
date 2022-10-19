#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const int inf=1e9+7;
int a[N],b[N],p[N],f[N*2],g[N*2];
int t,n,m;
int cnt;
// map<int,int> mp;
inline void add(int x)
{
	for (;x<=cnt;x+=x&(-x))
		++g[x];
}
inline int ask(int x)
{
	int ans=0;
	for (;x;x-=x&(-x))
		ans+=g[x];
	return ans;
}
inline void fz(int l,int r,int L,int R)
{
	if (l>r)
		return;
	int mid=(l+r)/2;
	int mnpos=L,sum=0;
	for (int i=L;i<R;++i)
		if (b[mid]>a[i])
			++sum;
	int mnsum=sum;
	for (int i=L;i<R;++i)
	{
		if (b[mid]>a[i])
			--sum;
		if (a[i]>b[mid])
			++sum;
		if (sum<mnsum)
		{
			mnsum=sum;
			mnpos=i+1;
		}
	}
	p[mid]=mnpos;
	fz(l,mid-1,L,p[mid]);
	fz(mid+1,r,p[mid],R);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		cnt=0;
		// mp.clear();
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			f[cnt++]=a[i];
		}
		a[n+1]=inf;
		for (int i=1;i<=m;++i)
		{
			scanf("%d",&b[i]);
			f[cnt++]=b[i];
		}
		sort(f,f+cnt);
		int tot=unique(f,f+cnt)-f;
		for (int i=1;i<=n;++i)
			a[i]=lower_bound(f,f+cnt,a[i])-f+1;
		for (int i=1;i<=m;++i)
			b[i]=lower_bound(f,f+cnt,b[i])-f+1;
		// for (int i=1;i<=cnt;++i)
		// 	if (i==1||f[i]!=f[i-1])
		// 		mp[f[i]]=++tot;
		// for (int i=1;i<=n;++i)
		// 	a[i]=mp[a[i]];
		// for (int i=1;i<=m;++i)
		// 	b[i]=mp[b[i]];
		sort(b+1,b+1+m);
		fz(1,m,1,n+1);
		cnt=0;
		for (int i=1,l=1;i<=n+1;++i)
		{
			while (p[l]==i&&l<=m)
			{
				f[++cnt]=b[l];
				++l;
			}
			if (i!=n+1)
				f[++cnt]=a[i];
		}
		for (int i=1;i<=cnt;++i)
			g[i]=0;
		long long ans=0;
		for (int i=cnt;i;--i)
		{
			ans+=ask(f[i]-1);
			add(f[i]);
		}
		cout<<ans<<endl;
	}
}