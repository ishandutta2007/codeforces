#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,x,y;
char s[MAXN];
int tx[MAXN],ty[MAXN];

bool check(int mid)
{
	for(int i=0;i+mid<=n;i++)
		if(abs(tx[i]+tx[n]-tx[i+mid]-x)+abs(ty[i]+ty[n]-ty[i+mid]-y)<=mid)
			return 1;
	return 0;
}

int main()
{
	scanf("%d%s%d%d",&n,s+1,&x,&y);
	if(abs(x)+abs(y)>n || (abs(x+y+n)&1))return 0*printf("-1\n");
	for(int i=1;i<=n;i++)
	{
		tx[i]=tx[i-1];ty[i]=ty[i-1];
		if(s[i]=='L')--tx[i];
		else if(s[i]=='R')++tx[i];
		else if(s[i]=='U')++ty[i];
		else --ty[i];
	}
	int l=0,r=n,mid,ans=n+1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans>n?-1:ans);
    return 0;
}