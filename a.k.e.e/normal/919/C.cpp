#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=2005,INF=1<<30;

int n,m,k;
char map[MAXN][MAXN];

int main()
{
	#ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int cnt,ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    	scanf("%s",map[i]+1);
    if(!k)
    {
    	printf("1\n");
    	return 0;
    }
    if(k==1)
    {
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=m;j++)
    			if(map[i][j]=='.')
    				ans++;
    	printf("%d\n",ans);
    	return 0;
    }
    for(int i=1;i<=n;i++)
    {
    	cnt=0;
    	for(int j=1;j<=m;j++)
    	{
    		if(map[i][j]=='.')cnt++;
    		else
			{
				if(cnt>=k)ans+=cnt-k+1;
				cnt=0;
			}
    	}
    	if(cnt>=k)ans+=cnt-k+1;
    }
    for(int j=1;j<=m;j++)
    {
    	cnt=0;
    	for(int i=1;i<=n;i++)
    	{
    		if(map[i][j]=='.')cnt++;
    		else
			{
				if(cnt>=k)ans+=cnt-k+1;
				cnt=0;
			}
    	}
    	if(cnt>=k)ans+=cnt-k+1;
    }
    printf("%d\n",ans);
    return 0;
}