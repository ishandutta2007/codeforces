#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)2e9+100)

ll n,x;


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll t;
		string s;
		cin>>t>>s;
		if(x==0 && s!="South")return cout<<"NO",0;
		if(x==20000 && s!="North")return cout<<"NO",0;
		if(s=="South")
		{
			x+=t;
			if(x>20000)return cout<<"NO",0;
		}
		if(s=="North")
		{
			x-=t;
			if(x<0)return cout<<"No",0;
		}
	}
	if(x)return cout<<"NO",0;
	cout<<"YES";
	return 0;
}