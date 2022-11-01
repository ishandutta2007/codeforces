#include <bits/stdc++.h>

using namespace std;
const int N=500001;

int f[N];
int sz[N];

int find_parent(int a)
{
    return (a==f[a])?a:f[a]=find_parent(f[a]);
}

void join(int a,int b)
{
    if((a=find_parent(a))==(b=find_parent(b))) return;
    if(sz[a]<sz[b]) swap(a,b);
    f[b]=a;
    sz[a]+=sz[b];
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
    {
        f[i]=i;
        sz[i]=1;
    }
	for(int o=0;o<m;o++)
    {
        int now;
        scanf("%d",&now);
        if(now==0) continue;
        int root;
        scanf("%d",&root);
        for(int i=0;i<now-1;i++)
        {
            int temp;
            scanf("%d",&temp);
            join(root,temp);
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",sz[find_parent(i)]);
    printf("\n");
	return 0;
}