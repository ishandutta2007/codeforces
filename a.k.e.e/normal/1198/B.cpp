#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=200005,MOD=998244353;

int n,a[MAXN],tim[MAXN],val[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    memset(val,-1,sizeof(val));
    int Q,op,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
    	scanf("%d%d",&op,&x);
    	if(op==1)
    	{
    		scanf("%d",&y);
    		tim[x]=i;a[x]=y;
    	}
    	else val[i]=x;
    }
    for(int i=Q;i;i--)
    	val[i]=max(val[i],val[i+1]);
    for(int i=1;i<=n;i++)
    	printf("%d ",max(a[i],val[tim[i]+1]));
    return 0;
}