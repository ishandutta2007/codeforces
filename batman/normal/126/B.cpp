#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define N (1001*1000)
#define MOD ((ll)1e9+7)
#define HASH (37)
string s;
ll l[N],r[N],p[N];
vector <ll> v;
ll tavan(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

bool check(ll x)
{
    for(int i=1;i<s.size()-x;i++)
    	if((l[i+x-1]-((l[i-1]*p[x])%MOD)+MOD)%MOD==l[x-1])
			return 1;     
    return 0;		
}

int main()
{ 
	p[0]=1;
	for(int i=1;i<N;i++)
		p[i]=p[i-1]*HASH,p[i]%=MOD;
    cin>>s;
    for(int i=0;i<s.size();i++)
    	l[i]=(s[i]-'a'+1)+((i)?l[i-1]*HASH:0),l[i]%=MOD;	
    	
    for(int i=s.size()-1;i>=0;i--)
    {
    	r[i]=(s[i]-'a'+1)*p[s.size()-i-1]+((i<s.size()-1)?r[i+1]:0),r[i]%=MOD;	
    	if(r[i]==l[s.size()-i-1])
    		v.push_back(s.size()-i);
    }
    //cout<<check(2)<<endl;
    sort(v.begin(),v.end());	
    ll left=-1,right=v.size();
    while(left<right-1)
    {
    	ll mid=(right+left)/2,x=v[mid];
    	if(check(x))
			left=mid;
		else
			right=mid;		
    }
    if(left==-1)cout<<"Just a legend";
    else for(int i=0;i<v[left];i++)cout<<s[i];
			
    return 0;
}