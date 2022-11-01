#include <bits/stdc++.h>

using namespace std;
const int N=200001;

int sz[N],d[N],heavy[N];
vector<int> v[N];

void dfs(int a,int p=-1)
{
    if(p!=-1) d[a]=d[p]+1;
    else d[a]=0;
    sz[a]=1;
    int m=0;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        sz[a]+=sz[to];
        if(sz[to]>m)
        {
            m=sz[to];
            heavy[a]=to;
        }
    }
}

int query(int a,bool t) //0-dist,1-next
{
    printf("%c %d\n",(t==0)?'d':'s',a);
    fflush(stdout);
    int res;
    scanf("%d",&res);
    if(res==-1) exit(0);
    return res;
}

void ans(int a)
{
    printf("! %d\n",a);
    fflush(stdout);
    exit(0);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int dx=query(1,0);
    if(dx==0) ans(1);
    int now=1;
    while(1)
    {
        int temp=now;
        vector<int> b;
        while(temp)
        {
            b.push_back(temp);
            temp=heavy[temp];
        }
        int a=b.back();
        int dist=query(a,0);
        int dy=(d[a]+dx-dist)/2;
        now=b[dy-d[now]];
        if(d[now]==dx) ans(now);
        now=query(now,1);
        if(d[now]==dx) ans(now);
    }
	return 0;
}