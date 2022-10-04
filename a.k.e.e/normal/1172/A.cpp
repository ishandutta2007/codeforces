#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=400005;

int n,b[MAXN],pos[MAXN];
bool hand[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		hand[x]=1;
	}
    for(int i=1;i<=n;i++)
    {
		scanf("%d",&b[i]);
		pos[b[i]]=i;
	}
	int front=1,rear=n;
	bool flag=(b[n]?1:0);
	for(int i=n;i>=n-b[n]+1;i--)
		if(b[i]!=i+b[n]-n){flag=0;break;}
	if(flag)
	{
		for(int i=b[n]+1;i<=n;i++)
			if(hand[i])
			{
				b[++rear]=i;
				hand[b[front++]]=1;
				hand[i]=0;
			}
			else
			{
				flag=0;
				break;
			}
		if(flag)return 0*printf("%d\n",n-b[n]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!hand[i])ans=max(ans,pos[i]-i+1);
	printf("%d\n",ans+n);
    return 0;
}