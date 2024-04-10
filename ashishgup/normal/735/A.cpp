#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	ll index1=s.find_first_of('G');
	ll index2=s.find_first_of('T');
	ll diff=abs(index1-index2);
	bool check=true;
	if(diff%k!=0)
	{
		check=false;
	}
	for(ll i=min(index1,index2);i<max(index1,index2);i+=k)
	{
		if(s[i]=='#')
		{
			check=false;
		}
	}
	if(check)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
    return 0;
}