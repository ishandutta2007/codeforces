#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=5005,INF=1<<30;

int n,m;
double x[MAXN];

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int a,b;
    double x;
    scanf("%d%d",&n,&m);
    double ans=INF;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d",&a,&b);
    	x=((double)a)/b;
    	ans=min(ans,x);
    }
    printf("%.8lf\n",ans*m);
    return 0;
}