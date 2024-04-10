#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, cur=0;
int l[N], r[N];
map<int, int> events;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)	
	{
		cin>>l[i]>>r[i];
		events[l[i]]++;
		events[r[i]+1]--;
	}	
	for(auto &it:events)
	{
		cur+=it.second;
		if(cur>2)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}