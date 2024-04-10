#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int n,i,j,f[N],vis[500005][26],ans;
char c[105];
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y)
		f[x]=y;
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
		scanf("%s",c);
		for(j=0;c[j];++j)
			vis[i][c[j]-'a']=1;
	}
	for(i=0;i<26;++i)
	{
		int p=0;
		for(j=1;j<=n;++j)
			if(vis[j][i])
				if(p==0)
					p=j;
				else
					uniot(p,j);
	}
	for(i=1;i<=n;++i)
		if(f[i]==0)
			++ans;
	cout<<ans;
}