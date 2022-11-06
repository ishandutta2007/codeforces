#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long LL;
int n;
int a[120],s[120],x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        s[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        scanf("%d%d",&x,&y);
        int ret=0;
        for(int i=1;i<=n;i++)
        if(s[i-1]>=x&&s[i-1]<=y&&s[n]-s[i-1]>=x&&s[n]-s[i-1]<=y)
        ret=i;
        printf("%d\n",ret);
    }
    return 0;
}