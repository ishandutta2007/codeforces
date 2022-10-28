#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ff first
#define ss second

const int N=2e5+5;

map<string, set<string> > m;

bool hasEnding(string a, string b)
{
	if(a.size()>=b.size())
	{
		return (0 == a.compare (a.length() - b.length(), b.length(), b));
	}
	else
	{
		return 0;
	}
}

bool check_suffix(string cur, string b)
{
	int ct=0;
	for(auto it:m[cur])
	{
		if(hasEnding(it, b))
		{
			ct++;
		}
	}
	if(ct>1)
		return 0;
	return 1;
}	

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s, num;
		int k;
		cin>>s>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>num;
			m[s].insert(num);
		}
	}
	cout<<m.size()<<endl;
	for(auto it:m)
	{
		set<string> ans;
		for(auto j:it.ss)
		{
			if(check_suffix(it.ff, j))
			{
				ans.insert(j);
			}
		}
		cout<<it.ff<<" ";
		cout<<ans.size()<<" ";
		for(auto j:ans)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
   	return 0;
}