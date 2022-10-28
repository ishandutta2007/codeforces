#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

string a, b, ans;
int n, m, have=0;
int fa[26], fb[26];

int check(int k)
{
	int reqd=0;
	vector<pair<char, int> > v;
	for(int i=0;i<26;i++)
	{
		reqd+=max(0LL, k*fb[i]-fa[i]);
		if(k*fb[i]-fa[i]>0)
			v.push_back({(char)(i+'a'), k*fb[i]-fa[i]});
	}
	if(reqd>have)
		return 0;
	ans.clear();
	for(int i=0;i<n;i++)
	{
		if(a[i]=='?')
		{
			if(v.size())
			{
				ans+=(v.back().first);
				v[v.size()-1].second--;
				if(v.back().second==0)
					v.pop_back();
			}
			else
				ans+='a';
		}
		else
			ans+=a[i];
	}
	return 1;
}

void binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	check(lo);
}

int32_t main()
{
	IOS;
	cin>>a>>b;
	n=a.size(), m=b.size();
	for(auto it:a)
	{
		if(it!='?')
			fa[it-'a']++;
		else
			have++;
	}
	for(auto it:b)
		fb[it-'a']++;
	binsearch(0, n/m);
	cout<<ans;
	return 0;
}