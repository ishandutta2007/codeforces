#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)510)

ll t;
string s;
bool cnt[10];

bool check(ll x,bool tt=0)
{
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<x;i++)
		cnt[s[i]-'0']^=1;
	string ex="";
	for(int i=0;i<10;i++)
		if(cnt[i])
			ex+=(char)(i+'0');
	if(ex.size()>(ll)s.size()-x)return 0;
	if(tt)return 1;
	for(int i=x;i<(ll)s.size()-(ll)ex.size();i++)
		if(s[i]>'0')
			return 1;
	for(int i=0;i<ex.size();i++)
	{
		if(s[i+(ll)s.size()-(ll)ex.size()]>ex[i])
			return 1;
		if(s[i+(ll)s.size()-(ll)ex.size()]<ex[i])
			return 0;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s.size()%2==1)
		{
			for(int i=0;i<(ll)s.size()-1;i++)
				cout<<'9';
			cout<<"\n";
			continue;
		}
		bool flg=1;
		for(int i=1;i<(ll)s.size()-1;i++)
			if(s[i]!='0')
				flg=0;
		if(flg && s[0]=='1' && s[(ll)s.size()-1]<='1')
		{
			for(int i=0;i<(ll)s.size()-2;i++)
				cout<<'9';
			cout<<"\n";
			continue;
		}
		ll l=0,r=s.size();
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(check(mid))l=mid;
			else r=mid;
		}
		while(1)
		{
			s[l]--;
			if(check(l+1,1))break;
		}
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<=l;i++)
			cnt[s[i]-'0']^=1,cout<<s[i];
		string ex="";
		for(int i=9;i>=0;i--)
			if(cnt[i])
				ex+=(char)(i+'0');
		for(int i=0;i<(ll)s.size()-(l+1)-(ll)ex.size();i++)cout<<'9';
		cout<<ex<<"\n";
	}
	return 0;
}