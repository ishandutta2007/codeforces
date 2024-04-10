#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=205;
const int MAX=1<<30;
struct qq{int x,y,z,last;}s[N*N*20];
int num,last[N*N*2];
int st,ed;
void init (int x,int y,int z)
{
    s[++num].x=x;s[num].y=y;s[num].z=z;
    s[num].last=last[x];last[x]=num;
    swap(x,y);z=0;
    s[++num].x=x;s[num].y=y;s[num].z=z;
    s[num].last=last[x];last[x]=num;
}
int h[N*N*2];
bool Bt ()
{
    memset(h,-1,sizeof(h));h[st]=1;
    queue<int> q;
    q.push(st);
    while (!q.empty())
    {
        int x=q.front();q.pop();
        for (int u=last[x];u!=-1;u=s[u].last)
        {
            int y=s[u].y;
            if (s[u].z>0&&h[y]==-1)
            {
                h[y]=h[x]+1;
                q.push(y);
            }
        }
    }
    return h[ed]!=-1;
}
int dfs (int x,int f)
{
    if (x==ed) return f;
    int s1=0;
    for (int u=last[x];u!=-1;u=s[u].last)
    {
        int y=s[u].y;
        if (s[u].z>0&&h[y]==h[x]+1&&s1<f)
        {
            int t=dfs(y,min(s[u].z,f-s1));
            s1+=t;
            s[u].z-=t;
            s[u^1].z+=t;
        }
    }
    if (s1==0) h[x]=-1;
    return s1;
}
char ss[N][N];
int n,m;
int ans=0;
int P (int x,int y)	{return (x-1)*m+y;}
int main()
{
	num=1;memset(last,-1,sizeof(last));
	
	scanf("%d%d",&n,&m);
	st=n*m*2+1;ed=st+1;
	for (int u=1;u<=n;u++)
	{
		scanf("%s",ss[u]+1);
		
		for (int i=1;i<=m;i++)
		{
			if (ss[u][i]=='#') ans++;
			if (ss[u][i]=='#'&&ss[u-1][i]=='#') 
			{
				ans--;
				init(st,P(u-1,i),1);
			}
			if (ss[u][i]=='#'&&ss[u][i-1]=='#')
			{
				ans--;
				init(P(u,i-1)+n*m,ed,1);
			}
			if (u!=1)
			{
				init(P(u-1,i),P(u-1,i)+n*m,MAX);
				init(P(u-1,i),P(u,i)+n*m,MAX);
				if (i!=1) init(P(u-1,i),P(u-1,i-1)+n*m,MAX);
				if (i!=1) init(P(u-1,i),P(u,i-1)+n*m,MAX);
			}
		}	
	}
	while (Bt()) ans=ans+dfs(st,MAX);
	printf("%d\n",ans);
    return 0;
}