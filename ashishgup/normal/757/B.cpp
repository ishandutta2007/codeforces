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

int main()
{
 	ll n;
 	cin>>n;
 	vector<ll> v(n);
 	vector<ll> freq(1e5+1,0);
 	for(ll i=0;i<n;i++)
 	{
 		cin>>v[i];
 		freq[v[i]]++;
	}
	/*for(ll i=0;i<100;i++)
	{
		cout<<freq[i]<<" ";
	}*/
	vector<bool> sieve(1e5+1,true);
	vector<ll> ans(1e5+1,0);
	ll i=2;
	for(;i<1e5+1;i++)
	{
		if(sieve[i]==true)
		{
			ans[i]+=freq[i];
			for(ll j=2;i*j<1e5+1;j++)
			{
				//cout<<i<<" "<<j<<" "<<freq[i*j]<<endl;
				ans[i]+=freq[i*j];
				sieve[i*j]=false;
			}
		}
	}
	ll max1=1;
	for(i=0;i<1e5+1;i++)
	{
		if(ans[i]>max1)
		{
			max1=ans[i];
		}
	}
	cout<<max1;
	return 0;
}