#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		string a,b;
		cin >> n >> m >> a >> b;
		if(a.size()<b.size())
		{
			cout << "NO\n";
			continue;
		}
		int p=1,flag=1;
		for(int i=a.size()-b.size()+1;i<a.size();i++)
			if(a[i]!=b[p++]) flag=0;
		int yi=0,ling=0;
		for(int i=0;i<=a.size()-b.size();i++)
			if(a[i]=='1') yi=1;
			else ling=1;
		if(b[0]=='1'&&!yi) flag=0;
		if(b[0]=='0'&&!ling) flag=0;
		if(!flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}