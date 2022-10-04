#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=15,MOD=1000000007;

int n,m,k,c[MAXN][MAXN],ans;
int use[MAXN],now[MAXN][MAXN];

inline int bit(int x)
	{return 1<<(x-1);}

int dfs(int x,int y)
{
	if(y>m)y=1,x++;
	if(x==n+1)return 1;
	now[x][y]=now[x-1][y]|now[x][y-1];
	int ans=0,t=k;
	for(int i=1;i<=k;i++)
		if(now[x][y]&bit(i))--t;
	if(t<n+m-x-y+1)return 0;
	t=-1;
	if(c[x][y])
	{
		if(now[x][y]&bit(c[x][y]))return 0;
		now[x][y]|=bit(c[x][y]);
		(ans+=dfs(x,y+1))%=MOD;
		now[x][y]=0;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			if(bit(i)&now[x][y])continue;
			now[x][y]|=bit(i);
			use[i]++;
			if(use[i]==1)
			{
				if(t<0)t=dfs(x,y+1);
				(ans+=t)%=MOD;
			}
			else (ans+=dfs(x,y+1))%=MOD;
			now[x][y]^=bit(i);
			use[i]--;
		}
	}
	return ans;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(n+m-1>k)return !printf("0\n");
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    	{
    		scanf("%d",&c[i][j]);
    		use[c[i][j]]=MOD;
    	}
    cout<<dfs(1,1)<<endl;
    return 0;
}