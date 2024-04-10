#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, ans=0;
int pref[N], suf[N], cnt[N];
string s;

void work(string &s)
{
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
			pref[i+1]=pref[i]+1;
		else
			pref[i+1]=pref[i]-1;
	}
	if(pref[n]%2 || pref[n]>2 || pref[n]<-2)
	{
		cout<<"0";
		exit(0);
	}
	if(pref[n]==0)
	{
		cout<<"0";
		exit(0);
	}
	suf[n+1]=1e9;
	for(int i=n;i>=1;i--)
	{
		suf[i]=min(suf[i+1], pref[i]);
	}
	if(pref[n]==2)
	{
		if(suf[1]<0)
			return;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='(' && suf[i]==2)
				cnt[i]++;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]==')' && suf[i]==-2)
				cnt[i]++;
		}
	}
}

void work2(string &s)
{
	for(int i=0;i<n;i++)
	{
		if(s[i]==')')
			pref[i+1]=pref[i]+1;
		else
			pref[i+1]=pref[i]-1;
	}
	if(pref[n]%2 || pref[n]>2 || pref[n]<-2)
	{
		cout<<"0";
		exit(0);
	}
	if(pref[n]==0)
	{
		cout<<"0";
		exit(0);
	}
	suf[n+1]=1e9;
	for(int i=n;i>=1;i--)
	{
		suf[i]=min(suf[i+1], pref[i]);
	}
	if(pref[n]==2)
	{
		if(suf[1]<0)
			return;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]==')' && suf[i]==2)
				cnt[n-i+1]++;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='('  && suf[i]==-2)
				cnt[n-i+1]++;
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>s;
	work(s);
	reverse(s.begin(), s.end());
	work2(s);
	for(int i=1;i<=n;i++)
		ans+=(cnt[i]==2);
	cout<<ans;
	return 0;
}