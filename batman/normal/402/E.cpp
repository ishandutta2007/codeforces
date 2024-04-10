#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define INF ((ll)1e15)
#define N (2002)

ll n,cnt,cnt2;
vector <ll> e[N],e2[N];
bool mark[N],mark2[N];

void dfs(ll x)
{
    mark[x]=1;
    cnt++;
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
            dfs(e[x][i]);
}

void dfs2(ll x)
{
    mark2[x]=1;
    cnt2++;
    for(int i=0;i<e2[x].size();i++)
        if(!mark2[e2[x][i]])
            dfs2(e2[x][i]);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            ll a;
            scanf("%d",&a);
            if(a && i!=j)e[i].push_back(j),e2[j].push_back(i);
        }
    dfs(1);
    dfs2(1);
    if(cnt==n && cnt2==n)printf("YES");
    else printf("NO");  
    
    return 0;
}