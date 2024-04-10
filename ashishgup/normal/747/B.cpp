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
    string s;
    cin>>s;
    if(n%4!=0)
    {
    	cout<<"===";
    	return 0;
	}
    vector<ll> v(5,0);
    for(ll i=0;i<n;i++)
    {
    	if(s[i]=='A')
    	{
    		v[0]++;
		}
		if(s[i]=='C')
		{
			v[1]++;
		}
		if(s[i]=='G')
		{
			v[2]++;
		}
		if(s[i]=='T')
		{
			v[3]++;
		}
		if(s[i]=='?')
		{
			v[4]++;
		}
	}
	ll max1=Max(v[0],v[1],v[2]);
	ll maxov=max(max1,v[3]);
	ll reqd=4*maxov-v[0]-v[1]-v[2]-v[3];
	bool check=false;
	if(v[4]>=reqd&&(v[4]-reqd)%4==0)
	{
		check=true;
	}
	if(check==false)
	{
		cout<<"===";
	}
	else
	{
		ll reqda=maxov-v[0]+((v[4]-reqd)/4);
		ll reqdc=maxov-v[1]+((v[4]-reqd)/4);
		ll reqdg=maxov-v[2]+((v[4]-reqd)/4);
		ll reqdt=maxov-v[3]+((v[4]-reqd)/4);
		for(ll i=0;i<n;i++)
		{
			if(s[i]!='?')
			{
				cout<<s[i];
			}
			else
			{
				if(reqda>0)
				{
					cout<<"A";
					reqda--;
					continue;
				}
				if(reqdc>0)
				{
					cout<<"C";
					reqdc--;
					continue;
				}
				if(reqdg>0)
				{
					cout<<"G";
					reqdg--;
					continue;
				}
				if(reqdt>0)
				{
					cout<<"T";
					reqdt--;
				}
			}
		}
	}
    return 0;
}