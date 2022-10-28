#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;

#define PI 3.141592653589793
#define MOD 1000000007

vector<ll> grundy;
int main()
{
    ll n;
    cin>>n;
    vector<ll> freq(10,0);
    ll num=n;
    ll ans=0;
    while(num!=0)
    {
    	ll rem=num%10;
    	freq[rem]++;
    	num=num/10;
	}
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0&&i*i!=n)
		{
			vector<ll> freqa(10,0);
			vector<ll> freqb(10,0);
			ll a=i;
			ll b=n/i;
			while(a!=0)
			{
				ll rem=a%10;
				freqa[rem]++;
				a=a/10;
			}
			while(b!=0)
			{
				ll rem=b%10;
				freqb[rem]++;
				b=b/10;
			}
			for(ll j=0;j<10;j++)
			{
				if(freq[j]>0&&freqa[j]>0)
				{
					ans++;
					break;
				}
			}
			for(ll j=0;j<10;j++)
			{
				if(freq[j]>0&&freqb[j]>0)
				{
					ans++;
					break;
				}
			}
		}
		else if(n%i==0)
		{
			vector<ll> freqa(10,0);
			ll a=i;
			while(a!=0)
			{
				ll rem=a%10;
				freqa[rem]++;
				a=a/10;
			}
			for(ll j=0;j<10;j++)
			{
				if(freq[j]>0&&freqa[j]>0)
				{
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans;
    return 0;
}