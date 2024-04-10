//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1100*100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ll n,l,x,y,a[N],com;
bool ans1,ans2,ans3;
int Sa1378
{ 
    IB
    cin>>n>>l>>x>>y;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    for(int i=0;i<n;i++)
    {
    	// put just for y
    	if(a[i]+x<=l)
    	{
    		ll ex=lower_bound(a,a+n,a[i]+x)-a;
    		if(0<=ex && ex<n && a[ex]==x+a[i])
    			ans1=true;
    	}
    	// put just for x
    	if(a[i]+y<=l)
    	{
    		ll ex=lower_bound(a,a+n,a[i]+y)-a;
    		if(0<=ex && ex<n && a[ex]==y+a[i])
    			ans2=true;
    	}
    	// put one point for both x and y
    	// +x
    	if(a[i]+x<=l)
    	{
    		if(a[i]+x+y<=l)
    		{
    			ll ex=a[i]+x+y,ex2=lower_bound(a,a+n,ex)-a;
    			if(0<=ex2 && ex2<n && a[ex2]==ex)
    				ans3=true,com=ex-y;
    		}
    		if(a[i]+x-y>=0)
    		{
    			ll ex=a[i]+x-y,ex2=lower_bound(a,a+n,ex)-a;
    			if(0<=ex2 && ex2<n && a[ex2]==ex)
    				ans3=true,com=ex+y;
    		}
    	}
    	// -x
    	if(a[i]-x>=0)
    	{
    		if(a[i]-x+y<=l)
    		{
    			ll ex=a[i]-x+y,ex2=lower_bound(a,a+n,ex)-a;
    			if(0<=ex2 && ex2<n && a[ex2]==ex)
    				ans3=true,com=ex-y;
    		}
    		if(a[i]-x-y>=0)
    		{
    			ll ex=a[i]-x-y,ex2=lower_bound(a,a+n,ex)-a;
    			if(0<=ex2 && ex2<n && a[ex2]==ex)
    				ans3=true,com=ex+y;
    		}
    	}
    }
    if(ans1 && ans2)
    	cout<<0<<endl;
    else if(ans1)
		cout<<1<<endl<<y<<endl;
	else if(ans2)
		cout<<1<<endl<<x<<endl;
	else if(ans3)
		cout<<1<<endl<<com<<endl;
	else
		cout<<2<<endl<<x<<" "<<y<<endl;			
    
    return 0;
}