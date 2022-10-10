#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define int long long
#define MIN LLONG_MIN
#define MAX LLONG_MAX
#define PB push_back
#define N 200001
#define MX 262144
#define LG 17
#define M 1000000007
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define LD long double
#define F first
#define S second
#define endl "\n"

int32_t main()
{
    LL i,j,lt,d,z,v,c,r,l,t1,k,h,u,q,ts,te,x,y,n,m;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    vector<pair<LL,LL>> sp,bs;
    for(i=1;i<=n;i++)
    {
    	cin>>x;
    	sp.PB({x,i});
    }
    for(i=0;i<m;i++)
    {
    	cin>>x>>y;
    	bs.PB({x,y});
    }
    sort(sp.begin(),sp.end());
    sort(bs.begin(),bs.end());
    LL ans[n+1];
    j=0;
    k=0;
    for(i=0;i<n;i++)
    {
    	while(j<m&&bs[j].F<=sp[i].F)
    	{
    		k+=bs[j].S;
    		j++;
    	}
    	ans[sp[i].S]=k;
    }
    for(i=1;i<=n;i++)
    	cout<<ans[i]<<" ";
}