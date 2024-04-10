//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.7 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (101*1000)
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
const ld sqr5=sqrt(5),p=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p,x)-tavan(1-p,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,a,b,in,m;
map <ll,bool> mp,mark;
map <ll,ll> ans,index;
map <ll,pair<vector <pair<ll,bool> >,ll> > e;
queue <ll> q;
ll lastans[N];
int Sa1378
{ 
    IB
    cin>>n>>a>>b;
    ll k=0;
    for(int i=0;i<n;i++)
    {
    	cin>>in;
    	mp[in]=1;
    	index[in]=i;
    		if(mp[a-in])
	    	{	
	    		e[in].second++;
    			e[in].first.PB({a-in,0});
    			if(a-in!=in)
    				e[a-in].first.PB({in,0}),e[a-in].second++;;
    			m++;
    		}	
    		if(mp[b-in] && a!=b)
    		{
	    		e[in].first.PB({b-in,1});
	    		e[in].second++;
	    		if(b-in!=in)
    				e[b-in].first.PB({in,1}),e[b-in].second++;;
    			m++;
    		}
    }
    for(map <ll,pair<vector <pair<ll,bool> >,ll> >::iterator it=e.begin();it!=e.end();it++)
    {
    	k++;
    	if(it->second.second==0)
    	{
    		cout<<"NO";
    		return 0;
    	}
    	if(it->second.second==1)
    		q.push(it->first);
    }
    if(k<n)
    {
    	cout<<"NO";
    	return 0;
    }
    k=0;
    while(!q.empty())
    {
    	ll ex=q.front();
    	q.pop();
    	if(e[ex].second==1 && !ans[ex])
    	{
    		
    	for(int i=0;i<e[ex].first.size();i++)
    	{
    		pair <ll,bool> pir=e[ex].first[i];
    		if(!mark[pir.first])
    		{
    			mark[pir.first]=1;
    			ans[pir.first]=pir.second+1;
    			ans[ex]=pir.second+1;	
    			for(int j=0;j<e[pir.first].first.size();j++)
    			{
    				e[e[pir.first].first[j].first].second--;
    				if(e[e[pir.first].first[j].first].second==1 && !mark[e[pir.first].first[j].first])
    					q.push(e[pir.first].first[j].first);
    			}
    					
    		}
    		e[pir.first].second--;
    	}	
    	}
    	mark[ex]=1;
    }
    for(map <ll,ll>::iterator it=ans.begin();it!=ans.end();it++,k++);
    if(k!=n)
    {
    	cout<<"NO";
    	return 0;
    }
    cout<<"YES\n";
    for(map <ll,ll>::iterator it=ans.begin();it!=ans.end();it++)
    	lastans[index[it->first]]=it->second;
    for(int i=0;i<n;i++)
		cout<<lastans[i]-1<<" ";	
    	
    return 0;
}