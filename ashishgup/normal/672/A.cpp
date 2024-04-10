#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

vector<int> v(int k)
{
	vector<int> cur;
	while(k>0)
	{
		cur.push_back(k%10);
		k/=10;
	}
	reverse(cur.begin(), cur.end());
	return cur;
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;;i++)
	{
		vector<int> cur=v(i);
		if(n>cur.size())
		{
			n-=cur.size();
			continue;
		}
		cout<<cur[n-1];
		return 0;
	}
	return 0;
}