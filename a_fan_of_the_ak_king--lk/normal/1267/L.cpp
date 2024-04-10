#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int t,n,k,l,i,j,p[1005],m;
char c[1000005],ans[1005][1005];
struct str{
	char c[1005];
}d[1005];
bool cmp(str a,str b)
{
	return strcmp(a.c,b.c)<0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&l,&k);
	scanf("%s",c);
	sort(c,c+n*l);
	m=1;
	while(1)
	{
		for(i=m;i<=k;++i)
		{
			if(c[j]!=c[j-1])
				m=i;
			ans[i][p[i]++]=c[j++];
		}
		if(p[k]==l)
			break;
	}
	int u=n*l;
	for(i=1;i<=n;++i)
		for(;p[i]<l;++p[i])
			ans[i][p[i]]=c[--u];
	for(i=1;i<=n;++i)
		memcpy(d[i].c,ans[i],sizeof(ans[i]));
	sort(d+1,d+1+n,cmp);
	for(i=1;i<=n;++i)
		printf("%s\n",d[i].c);
}