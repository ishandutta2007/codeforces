#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N];
map<int, int> m;
vector<int> pw;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	int cur=1;
	while(cur<=2e9)
	{
		pw.push_back(cur);
		cur*=2;
	}
	int ans=0;
	for(auto it:m)
	{
		int check=0;
		for(auto j:pw)
		{
			if(m.find(j-it.first)!=m.end())
			{
				if((j==(2*it.first)) && it.second==1)
					continue;
				check=1;
			}
		}
		if(!check)
			ans+=it.second;
	}
	cout<<ans;
	return 0;
}