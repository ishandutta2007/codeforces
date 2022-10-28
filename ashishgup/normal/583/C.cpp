#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n;
int a[N];
vector<int> ans;
multiset<int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n*n;i++)
	{
		cin>>a[i];
		m.insert(a[i]);
	}
	while(m.size())
	{
		int elem=*(--m.end());
		for(auto it:ans)
		{
			m.erase(m.find(__gcd(it, elem)));
			m.erase(m.find(__gcd(it, elem)));
		}
		m.erase(m.find(elem));
		ans.push_back(elem);
	}
	for(auto it:ans)
		cout<<it<<" ";
	return 0;   
}