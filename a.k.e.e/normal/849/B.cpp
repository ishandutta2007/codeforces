#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=1005;
const double eps=1e-9;

int n;
ll y[MAXN];
bool vis[MAXN];

bool equ(double a,double b)
{
	return a-b<eps && b-a<eps;
}

int main()
{
	#ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    double dy,dy2;
    int f1,f2;
    bool flag;
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>y[i];
    
    for(int i=2;i<=n;i++)
    {
    	dy=(y[i]-y[1])/(i-1.0);
    	memset(vis,false,sizeof(vis));
    	vis[1]=vis[i]=true;
    	for(int j=1;j<=n;j++)
    		if(equ(dy*(j-1)+y[1],y[j]))vis[j]=true;
    	f1=f2=0;
    	for(int j=1;j<=n;j++)
    		if(!vis[j])
    		{
    			if(f1)
				{
					f2=j;
					break;
				}
				f1=j;
    		}
    	if(!f1)continue;
    	if(!f2)
    	{
	    	printf("Yes\n");
	    	return 0;
    	}
    	
    	flag=false;
    	dy2=(y[f2]-y[f1])/((double)f2-f1);
    	for(int j=1;j<=n;j++)
    		if(equ(dy*(j-f1)+y[f1],y[j]))
			{
				if(vis[j])
				{
					flag=true;
					break;
				}
				vis[j]=true;
			}
		if(flag)continue;
    	flag=false;
    	for(int j=1;j<=n;j++)
    		if(!vis[j])
    		{
    			flag=true;
    			break;
    		}
    	if(flag)continue;
    	printf("Yes\n");
    	return 0;
    }
    
	dy=y[3]-y[2];
	memset(vis,false,sizeof(vis));
	vis[2]=vis[3]=true;
	for(int j=1;j<=n;j++)
		if(equ(dy*(j-2)+y[2],y[j]))vis[j]=true;
	if(vis[1])
    {
	    printf("No\n");
	    return 0;
	}
	for(int j=2;j<=n;j++)
		if(!vis[j])
	    {
		    printf("No\n");
		    return 0;
		}
	printf("Yes\n");
	return 0;
}