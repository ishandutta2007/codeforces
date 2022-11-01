#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
int arr[N];
int id[N];
int st[N][20];
vector<int> v[N/2];
vector<int> vis(N/2,0);

void sparse_table()
{
    for(int o=N-1;o>=1;o--)
    {
        st[o][0]=arr[o];
        for(int i=1;o+(1<<i)<N;i++) st[o][i]=max(st[o][i-1],st[o+(1<<(i-1))][i-1]);
    }
}

int msb(int n)
{
    return 31-__builtin_clz(n);
}

int query(int l,int r)
{
    int t=msb(r-l+1);
    return max(st[l][t],st[r-(1<<t)+1][t]);
}

bool dfs(int a,int p=-1)
{
    vis[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        if(vis[to]==1) return 0;
        if(dfs(to,a)==0) return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        arr[a[i]]=b[i];
        id[a[i]]=i;
    }
    sparse_table();
    int edges=0;
    for(int i=0;i<n;i++)
    {
        int now=a[i]+1;
        while(now<b[i])
        {
            int l=now;
            int r=b[i]-1;
            if(query(l,r)<b[i]) break;
            if(query(l,l)>b[i]) r=l;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(query(now,m)>b[i]) r=m;
                else l=m;
            }
            v[i].push_back(id[r]);
            v[id[r]].push_back(i);
            edges++;
            now=r+1;
        }
        if(edges>n-1) break;
    }
    bool res=(edges==n-1);
    res&=dfs(0);
    for(int i=0;i<n;i++) res&=vis[i];
    if(res) printf("YES\n");
    else printf("NO\n");
    return 0;
}