#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1005;

int n;
int ask(int x,int y,int z)
{
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int res[MAXN];
int sel[15][2],val[7][7],num[7][7];
ll f[7];int sig[7],q[7];
int ans[7];
struct Data
{
	int a[3],val;
	Data(){}
	Data(int x,int y,int z,int val):val(val)
		{a[0]=x;a[1]=y;a[2]=z;}
	inline bool check()const
	{
		return min(min(ans[a[0]],ans[a[1]]),ans[a[2]])+
			max(max(ans[a[0]],ans[a[1]]),ans[a[2]])==val;
	}
}d[MAXN];

bool dfs(int cur)
{
	if(cur>10)
	{
		memset(f,0,sizeof(f));
		memset(sig,0,sizeof(sig));
		ll cur1=0;
		int front=1,rear=0,u;
		f[1]=0;sig[1]=1;q[++rear]=1;
		while(front<=rear)
		{
			u=q[front++];
			for(int i=1;i<=5;i++)
			{
				if(!num[u][i])continue;
				if(!sig[i])
				{
					sig[i]=-sig[u];
					f[i]=val[u][i]-f[u];
					q[++rear]=i;
				}
				else if(sig[u]+sig[i]==0)
				{
					if(f[u]+f[i]!=val[u][i])
						return 0;
				}
				else
				{
					ll t=val[u][i]-f[u]-f[i];
					if(t&1)return 0;
					cur1=((t*sig[i])>>1);
				}
			}
		}
		for(int i=1;i<=5;i++)
			ans[i]=f[i]+sig[i]*cur1;
		for(int i=1;i<=10;i++)
			if(!d[i].check())return 0;
		return 1;
	}
	int u,v;
	for(int i=0;i<=2;i++)
	{
		u=sel[cur][0]=d[cur].a[(i+1)%3];
		v=sel[cur][1]=d[cur].a[(i+2)%3];
		if(num[u][v] && val[u][v]!=d[cur].val)continue;
		val[u][v]=val[v][u]=d[cur].val;++num[u][v];++num[v][u];
		if(dfs(cur+1))return 1;
		--num[u][v];--num[v][u];
	}
	return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    int cur=0;
    while(1)
    {
    	if(cur==n)break;
    	cur+=5;
    	if(cur>n)cur=n;
    	int cnt=0;
	    for(int i=1;i<=3;i++)
	    	for(int j=i+1;j<=4;j++)
	    		for(int k=j+1;k<=5;k++)
	    			d[++cnt]=Data(i,j,k,ask(cur-5+i,cur-5+j,cur-5+k));
	    memset(num,0,sizeof(num));
	    dfs(1);
	    for(int i=1;i<=5;i++)
	    	res[cur-5+i]=ans[i];
	}
	printf("!");
	for(int i=1;i<=n;i++)
		printf(" %d",res[i]);
	fflush(stdout);
    return 0;
}