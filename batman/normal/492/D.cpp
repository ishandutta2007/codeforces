#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,x,y,a;
int main()
{ 
    cin>>n>>x>>y;
    ll ex=x*y/__gcd(x,y),stpx=ex/x,stpy=ex/y;
    
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	a%=stpx+stpy;
    	if(!a)
    	{
    		cout<<"Both\n";
    		continue;
    	}
    	ll l=0,r=((ll)1e14);
    	while(l<r-1)
    	{
    		ll mid=l+r>>1;
    		if((mid/stpx)+(mid/stpy)>=a)
    			r=mid;
    		else
				l=mid;
    	}
    	
    	if(!(r%stpx) && !(r%stpy))
    		cout<<"Both\n";
    	else if(r%stpx)
			cout<<"Vova\n";
		else
			cout<<"Vanya\n";		
    }
    return 0;
}