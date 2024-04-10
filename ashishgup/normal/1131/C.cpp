#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];
deque<int> ans;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	ans.push_back(a[n]);
	for(int i=n-1;i>=1;i--)
	{
		if(i%2)
			ans.push_front(a[i]);
		else
			ans.push_back(a[i]);
	}
	while(ans.size())
	{
		cout<<ans.front()<<" ";
		ans.pop_front();
	}
	return 0;
}