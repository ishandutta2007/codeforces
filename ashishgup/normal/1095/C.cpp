#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k;

int32_t main()
{
	IOS;
	cin>>n>>k;
	int min=__builtin_popcount(n);
	if(k<min)
	{
		cout<<"NO";
		return 0;
	}	
	priority_queue<int> pq;
	for(int i=0;i<31;i++)
	{
		if((n>>i)&1)
			pq.push(i);
	}
	while(pq.size()<k)
	{
		if(pq.top()==0)
		{
			cout<<"NO";
			return 0;
		}
		int cur=pq.top();
		pq.pop();
		pq.push(cur-1);
		pq.push(cur-1);
	}
	cout<<"YES"<<endl;
	while(pq.size())
	{
		cout<<(1LL<<pq.top())<<" ";
		pq.pop();
	}
	return 0;
}