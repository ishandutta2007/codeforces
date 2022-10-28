#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int ans[N];
map<int, vector<int> > event;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int l, r;
		cin>>l>>r;
		event[l].push_back(+1);
		event[r+1].push_back(-1);
	}
	int prev=event.begin()->first;
	int cur=0;
	for(auto it:event)
	{
		ans[cur]+=it.first-prev;
		for(auto j:it.second)
			if(j==-1)
				cur--;
		for(auto j:it.second)
			if(j==1)
				cur++;
		prev=it.first;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}