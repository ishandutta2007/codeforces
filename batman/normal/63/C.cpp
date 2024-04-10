#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)12)
#define INF ((ll)2e9+100)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n;
string s[N],ans=".";
pair <ll,ll> a[N];

string _string(ll x)
{
	string ex;
	while(x)ex+=(char)((x%10)+'0'),x/=10;
	while(ex.size()<4)ex+='0';
	reverse(ex.begin(),ex.end());
	return ex;
}

bool check(string x)
{
	bool mark[10]={};
	for(int i=0;i<x.size();i++)
	{
		if(mark[(x[i]-'0')])return 0;
		mark[(x[i]-'0')]=1;
	}
	return 1;
}

pair <ll,ll> compare(string x,string y)
{
	ll same=0,oskol=0;
	bool mark[10]={};
	for(int i=0;i<4;i++)
	{
		if(x[i]==y[i])same++;
		mark[(x[i]-'0')]=1;	
	}
	for(int i=0;i<4;i++)
		if(mark[(y[i]-'0')])
			oskol++;
	return {same,oskol-same};
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i]>>a[i].first>>a[i].second;
	for(int i=0;i<10000;i++)
		if(check(_string(i)))
		{
			bool flg=1;
			for(int j=0;j<n;j++)
				if(compare(s[j],_string(i))!=a[j])
					flg=0;
			if(flg && ans!=".")return cout<<"Need more data",0;
			if(flg)ans=_string(i);
		}
	if(ans==".")return cout<<"Incorrect data",0;
	cout<<ans;
	return 0;
}