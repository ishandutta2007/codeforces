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
    ll n,m;
    cin>>n>>m;
    vector<ll> v(m);
    vector<ll> count(1001,0);
    vector<ll> count1(1001,0);
    for(ll i=0;i<m;i++)
    {
    	cin>>v[i];
    	ll store=v[i];
    	count1[store]++;
    	for(ll j=1;j<=store;j++)
    	{
    		count[j]++;
		}
	}
	ll total=0;
	ll maxsum=0;
	for(ll i=1000;i>=1;i--)
	{
		//cout<<count[i]<<" ";
		if(total+count[i]>=n)
		{
			maxsum+=(n-total)*i;
			break;
		}
		total+=count[i];
		maxsum+=count[i]*i;
	}
	//cout<<endl;
	ll minsum=0;
	total=0;
	if(total<n)
	{
		total+=count1[1];
		minsum+=min(count1[1],n);
	}
	for(ll i=2;i<1001;i++)
	{
		//cout<<count[i]<<" ";
		if(total+count1[i]*i>n)
		{
			ll check=1;
			while(check*i+total<n&&check<count1[i])
			{
				check++;
			}
			check--;
			minsum+=check*(i*(i+1))/2;
			total+=check*i;
			ll temp=i;
			while(total<n)
			{
				total++;
				minsum+=temp--;
			}
			break;
		}
		total+=count1[i]*i;
		minsum+=count1[i]*(i*(i+1))/2;
		if(total>=n)
		{
			break;
		}
	}
	//cout<<endl;
	cout<<maxsum<<" "<<minsum;
	return 0;
}