#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

typedef long long ll;
const int MAXN=25;

int n,m;
ll k,a[MAXN][MAXN];
vector<ll> c[MAXN],d[MAXN];

void dfs(int x,int y,ll cur)
{
    if(!x || !y)return;
    if(x+y==n+1)
    {
        c[x].pb(cur);
        return;
    }
    dfs(x-1,y,cur^a[x-1][y]);
    dfs(x,y-1,cur^a[x][y-1]);
}
void dfs2(int x,int y,ll cur)
{
    if(x>n || y>m)return;
    if(x+y==n+1)
    {
        d[x].pb(cur);
        return;
    }
    dfs2(x+1,y,cur^a[x][y]);
    dfs2(x,y+1,cur^a[x][y]);
}

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    cin>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    dfs(n,m,a[n][m]);
    for(int i=1;i<=n;i++)
        sort(c[i].begin(),c[i].end());
    dfs2(1,1,0);
    ll ans=0;
    for(int i=1;i<=n;i++)
    	for(int j=0;j<d[i].size();++j)
    	{
    		ans+=upper_bound(c[i].begin(),c[i].end(),d[i][j]^k)-
				lower_bound(c[i].begin(),c[i].end(),d[i][j]^k);
		}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<c[i].size();++j)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
	cout<<"------------------"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<d[i].size();++j)
			cout<<d[i][j]<<" ";
		cout<<endl;
	}*/
    cout<<ans<<endl;
    return 0;
}