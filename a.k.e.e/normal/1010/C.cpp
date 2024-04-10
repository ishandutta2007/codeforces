#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int gcd(int x,int y)
	{return y?gcd(y,x%y):x;}

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int n,k,x,now;
    scanf("%d%d",&n,&k);
    now=k;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&x);
    	now=gcd(now,x);
    }
    printf("%d\n",k/now);
    for(int i=0;i<k;i+=now)
    	printf("%d ",i);
    return 0;
}