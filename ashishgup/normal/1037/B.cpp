#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, s, small=0, larger=0, ans=0;
int a[N];
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int> > pq2;

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<s)
		{
			small++;
			pq.push(a[i]);
		}
		if(a[i]>s)
		{
			larger++;
			pq2.push(a[i]);
		}
	}	
	while(larger>n/2)
	{
		ans+=(pq2.top()-s);
		pq2.pop();
		larger--;
	}
	while(small>n/2)
	{
		ans+=(s-pq.top());
		pq.pop();
		small--;
	}
	cout<<ans;
	return 0;
}