#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=105,INF=1<<30;

int n,m,a[MAXN];

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    	if(!(m%a[i]))
    		ans=max(ans,a[i]);
    printf("%d\n",m/ans);
    return 0;
}