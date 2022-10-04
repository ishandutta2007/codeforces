#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=200005,INF=1<<30;

int n,a[MAXN];

inline int Abs(int x)
{
    return x>0?x:-x;
}

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    int del=0;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	if(a[i]==a[i-1])
    	{
            printf("NO\n");
            return 0;
    	}
    	if(i>1 && Abs(a[i]-a[i-1])>1)
    	{
    		if(!del)del=Abs(a[i]-a[i-1]);
    		else if(Abs(a[i]-a[i-1])!=del)
    		{
    			printf("NO\n");
    			return 0;
    		}
    	}
    }
    if(!del)
    {
    	printf("YES\n%d %d\n",1,1000000000);
    	return 0;
    }
    int miny=a[1]%del,nowy;
    if(!miny)miny=del;
    nowy=miny;
    for(int i=2;i<=n;i++)
    {
    	if(a[i]==a[i-1]+1)nowy++;
    	if(a[i]==a[i-1]-1)
        {
            nowy--;
            if(nowy<=0)
            {
                printf("NO\n");
    			return 0;
            }
        }
    	miny=max(miny,nowy);
    }
    if(del<miny)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n%d %d\n",1000000000,del);
    return 0;
}