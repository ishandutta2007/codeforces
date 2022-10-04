#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

using namespace std;

typedef long long ll;
const int MAXN=2005;

int n,m,x,a[MAXN],b[MAXN],s[MAXN],la[MAXN],lb[MAXN];

int main()
{
    cin>>n>>m;
    rep(i,1,n){cin>>a[i];la[i]=1<<30;}
    rep(i,1,m){cin>>b[i];lb[i]=1<<30;}
    cin>>x;
    rep(i,1,n)
    {
    	s[i]=s[i-1]+a[i];
    	rep(j,1,i)
    		la[i-j+1]=min(la[i-j+1],s[i]-s[j-1]);
    }
    rep(i,1,m)
    {
    	s[i]=s[i-1]+b[i];
    	rep(j,1,i)
    		lb[i-j+1]=min(lb[i-j+1],s[i]-s[j-1]);
    }
    int ans=0;
    rep(i,1,n)
    	rep(j,1,m)
    		if((ll)la[i]*lb[j]<=x)
    			ans=max(ans,i*j);
    cout<<ans<<endl;
    return 0;
}