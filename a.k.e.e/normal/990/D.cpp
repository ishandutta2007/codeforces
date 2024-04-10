#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN=1005;

int n,a,b,s[MAXN][MAXN];
int xtq=0;

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d%d",&n,&a,&b);
    if(a<b)
    {
    	xtq=1;
    	swap(a,b);
    }
    if(b!=1 || ((n==2 || n==3) && a==1 && b==1))
    {
    	printf("NO");
    	return 0;
    }
    for(int i=1;i<=n-a;i++)
    	s[i][i+1]=s[i+1][i]=1;
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(i==j)printf("0");
    		else printf("%d",s[i][j]^xtq);
    	}
    	printf("\n");
    }
    return 0;
}