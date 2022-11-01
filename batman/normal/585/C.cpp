#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll a,b;
string s;

void gcd(ll x,ll y)
{
	if(x==y)
	{
		if(x!=1){cout<<"Impossible";exit(0);}
		return ;
	}
	if(x>y)
	{
		ll p=x/y-(x%y==0);
		string ex="";
		while(p)
		{
			ex=(char)((p%10)+'0')+ex;
			p/=10;
		}
		s+=ex+'A';
		gcd(x%y+((x%y)?0ll:y),y);
		return ;	
	}
	ll p=y/x-(y%x==0);
	string ex="";
	while(p)
	{
		ex=(char)((p%10)+'0')+ex;
		p/=10;
	}
	s+=ex+'B';
	gcd(x,y%x+((y%x)?0ll:x));
}

int main ()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b;
	gcd(a,b);
	cout<<s;
	return 0;
}