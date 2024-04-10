#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=500005,M=998244353;
int n,i,a[N*2],f[N],top,j,Next[N],last[N],insta[N],s;
struct str{
	int l,r;
}p[N];
bool cmp(str a,str b)
{
	return a.r<b.r;
}
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&p[i].l,&p[i].r);
		a[p[i].l]=i;
		a[p[i].r]=i;
	}
	for(i=1;i<=2*n;++i)
		if(insta[a[i]])
		{
			for(j=Next[a[i]];j;j=Next[j])
			{
				int x=Find(j),y=Find(a[i]);
				//cout<<j<<' '<<a[i]<<endl;
				if(x!=y)
					f[x]=y;
				else
				{
					puts("NO");
					return 0;
				}
			}
			insta[a[i]]=0;
			int x=a[i];
			Next[last[x]]=Next[x];
			if(Next[x])
				last[Next[x]]=last[x];
			else
				top=last[x];
		}
		else
		{
			insta[a[i]]=1;
			Next[top]=a[i];
			last[a[i]]=top;
			top=a[i];
		}
	for(i=1;i<=n;++i)
		if(Find(i)==i)
			++s;
	puts(s==1?"YES":"NO");
}