//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.3 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (101*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
const ll HASH=1e16+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,m;
vector <ll> e[N];

bool check_odd()
{
	ll dis[N]={},par[N]={};
	bool mark[N]={};
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			queue <ll> q;
			q.push(i);
			mark[i]=1;
			while(!q.empty())
			{
				ll ex=q.front();
				q.pop();
				for(int i=0;i<e[ex].size();i++)
				{
					if(mark[e[ex][i]])
					{
						if((dis[e[ex][i]]+dis[ex])%2==0)
							return 1;
					}
					else
					{
						par[e[ex][i]]=ex;
						dis[e[ex][i]]=dis[ex]+1;
						mark[e[ex][i]]=1;
						q.push(e[ex][i]);
					}	
				}
			}
		}
	
	return 0;
}


ll check_odd2()
{
	ll ans=0,dis[N]={},par[N]={};
	bool mark[N]={};
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			queue <ll> q;
			q.push(i);
			ll cnt[2]={};
			cnt[0]++;
			mark[i]=1;
			while(!q.empty())
			{
				ll ex=q.front(),p=0;
				q.pop();	
				for(int i=0;i<e[ex].size();i++)
				{
					if(!mark[e[ex][i]])
					{
						p++;
						par[e[ex][i]]=ex;
						dis[e[ex][i]]=dis[ex]+1;
						mark[e[ex][i]]=1;
						q.push(e[ex][i]);	
					}
				}
				ans+=cnt[!(dis[ex]%2)]*p;
				cnt[!(dis[ex]%2)]+=p;
				ans+=p*(p-1)/2;
			}
		}
	return ans;
}

int Sa1378
{ 
    IB
    scanf("%I64d %I64d",&n,&m);
    for(int i=0;i<m;i++)
    {
    	ll a,b;
    	scanf("%I64d %I64d",&a,&b);
    	e[a].PB(b);
    	e[b].PB(a);
    }
    if(m==0)
    {
    	printf("3 %I64d",n*(n-1)*(n-2)/6);
    	return 0;
    }
    if(check_odd())
    {
    	printf("0 1");
    	return 0;
    }
	ll ex=check_odd2();
	if(ex)
	{
		printf("1 %I64d",ex);
		return 0;
	}
	printf("2 %I64d",m*(n-2));			
    return 0;
}