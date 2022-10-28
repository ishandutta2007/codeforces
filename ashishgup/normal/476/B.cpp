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

ll fact(ll n)
{
	ll ans=1;
	for(ll i=2;i<=n;i++)
	{
		ans*=i;
	}
	return ans;
}
int main()
{
	string a,b;
	cin>>a>>b;
	ll n=a.size();
	ll pos1=0;
	ll pos2=0;
	ll ques=0;
	for(ll i=0;i<n;i++)
	{
		if(a[i]=='+')
		{
			pos1++;
		}
		else
		{
			pos1--;
		}
		if(b[i]=='+')
		{
			pos2++;
		}
		else if(b[i]=='?')
		{
			ques++;
		}
		else
		{
			pos2--;
		}
	}
	double ans;
	if(abs(pos1-pos2)>ques)
	{
		ans=0;
	}
	else
	{
		//cout<<ques<<endl;
		ll plus1=abs(pos1-pos2);
		double plus=(double)(ques-plus1)/2;
		if(ceil(plus)!=floor(plus))
		{
			ans=0;
		}
		else
		{
			ans=fact(ques)/(fact(ques-plus)*fact(plus));
			ans=ans/(1<<ques);
		}
		//cout<<ans;
	}
	cout<<fixed<<showpoint<<setprecision(10)<<ans;
	
	return 0;
}