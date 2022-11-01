//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.8 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (1001*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI ((ld)3.1415926535897932384626433832795028841971)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i*i<=x;i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll m,h1,h2,x1,x2,y11,y2,a1,a2;
ll step[N],ex,just1_;
pair <ll,ll> p1;
bool just1;
int Sa1378
{ 
    IB
    cin>>m>>h1>>a1>>x1>>y11>>h2>>a2>>x2>>y2;
    ex=h1;
    for(int i=1;;i++)
    {
    	step[ex]=i;
    	ex=ex*x1+y11;
    	ex%=m;
    	if(step[ex])
    	{
    		ll l=i-step[ex]+1;
    		if(!step[a1])
    			return cout<<-1,0;
			if(step[a1]<step[ex])
				just1=1,just1_=step[a1]-1;
			else
				p1={(step[a1]-1),l};
			break;			
    	}
    }
    fill(step,step+m,0);
    ex=h2;	
    for(int i=1;;i++)
    {
    	step[ex]=i;
    	ex=ex*x2+y2;
    	ex%=m;
    	if(step[ex])
    	{
    		if(!step[a2])
    			return cout<<-1,0;
    		ll l=i-step[ex]+1;
			step[a2]--;	
			if(step[a2]<step[ex])
			{
				if(just1 && step[a2]==just1_ || (!just1 && (step[a2]-p1.first)>=0 && (step[a2]-p1.first)%p1.second==0))
					return cout<<step[a2],0;
				else
					return cout<<-1,0;
			}		
			else
			{
				if(just1 && (just1_-step[a2])>=0 && (just1_-step[a2])%l==0)
					return cout<<step[a2],0;
				else if(just1)
					return cout<<-1,0;	
				else
				{
					for(ll i=0;i<N*10;i++)
						if((i*p1.second+p1.first-step[a2])>=0 && (i*p1.second+p1.first-step[a2])%l==0)
							return cout<<i*p1.second+p1.first,0;
					return cout<<-1,0;
				}
			}			
    	}
    }
    
    return 0;
}