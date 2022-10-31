#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int t,n,m,a[105][105],i,j,s,ans=1<<30,p[105],k;
struct str{
	int b,x;
}b[105];
bool cmp(str a,str b)
{
	return a.b<b.b;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(i=1;i<n;++i)
	{
		for(j=1;j<=m;++j)
		{
			b[j].b=a[j][n]-a[j][i];
			b[j].x=j;
		}
		sort(b+1,b+1+m,cmp);
		s=0;
		for(j=0;j<=m;++j)
		{
			s+=b[j].b;
			if(s<=0)
				if(ans>m-j)
				{
					ans=m-j;
					for(k=j+1;k<=m;++k)
						p[k-j]=b[k].x;
				}
		}
	}
	cout<<ans<<endl;
	for(i=1;i<=ans;++i)
		printf("%d ",p[i]);
}