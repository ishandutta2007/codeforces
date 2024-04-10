#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, zeroes;
string ans="1";
string a[N];

bool zero(string &s)
{
	bool check=1;
	for(auto &it:s)
		check&=(it=='0');
	return check;
}

bool check(string &s)
{
	map<char, int> m;
	for(auto &it:s)
		if(it!='0')
			m[it]++;
	if(m.size()>1 || m.find('1')==m.end() || m['1']>1)
		return 0;
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(zero(a[i]))
		{
			cout<<0;
			return 0;
		}
		if(check(a[i]))
		{	
			reverse(a[i].begin(), a[i].end());
			for(auto &it:a[i])
			{
				if(it=='0')
					zeroes++;
				else
					break;
			}
		}
		else
			ans=a[i];
	}
	for(int i=1;i<=zeroes;i++)
		ans+='0';
	cout<<ans;
	return 0;
}