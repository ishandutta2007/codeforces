#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector> 

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=100005;

int n,m;
ll s[MAXN];
vector<int> v[MAXN];
inline bool cmpbig(int x,int y){return x>y;}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x,y,msize=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d",&x,&y);
		v[x].pb(y); 
    }
    for(int i=1;i<=m;i++)
    {
    	sort(v[i].begin(),v[i].end(),cmpbig);
    	for(int j=0;j<v[i].size();++j)
    	{
    		if(j)v[i][j]+=v[i][j-1];
    		if(v[i][j]>0)s[j]+=v[i][j];
    	}
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    	ans=max(ans,s[i]);
    printf("%lld\n",ans);
    return 0;
}