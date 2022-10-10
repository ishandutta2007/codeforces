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
    LL i,j,lt,z,v,c,r,l,t1,k,h,u,q,ts,te,x,y,n,m,s,b;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    vector<pair<LL,LL>> pts;
    LL ctx[51]={0},cty[51]={0};
    for(i=0;i<=4*n;i++)
    {
    	cin>>x>>y;
    	pts.PB({x,y});
    	ctx[x]++;
    	cty[y]++;
    }
    for(i=0;i<=4*n;i++)
    {
    	x=pts[i].F;
    	y=pts[i].S;
    	ctx[x]--;
    	cty[y]--;
    	set<LL> xo,yo;
    	for(j=0;j<51;j++)
    	{
    		if(ctx[j])
    			xo.insert(j);
    		if(cty[j])
    			yo.insert(j);
    	}
    	// cout<<xo.size()<<" "<<yo.size()<<endl;
    	// cout<<x<<" "<<y<<endl;
    	if(xo.size()==2&&yo.size()==2||1)
    	{
    		LL sx=*xo.begin();
    		LL sy=*yo.begin();
    		LL ex=*xo.rbegin();
    		LL ey=*yo.rbegin();
    		// cout<<x<<" "<<y<<endl;
    		// cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
    		if((ex-sx)==(ey-sy))
    		{
    			for(j=0;j<=4*n;j++)
    				if((pts[j].F==sx||pts[j].F==ex)||(pts[j].S==sy||pts[j].S==ey)||i==j)
    					continue;
    				else
    				{
    					// cout<<j<<endl;
    					break;
    				}
    			if(j==4*n+1)
    			{
	    			cout<<x<<" "<<y;
	    			return 0;
	    		}
    		}
    	}
    	ctx[x]++;
    	cty[y]++;
    }
}