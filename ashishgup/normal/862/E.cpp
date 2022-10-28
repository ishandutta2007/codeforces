#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, q, sum=0;
int a[N], b[N], sufB[N];
set<int> s;

int odd(int l, int r)
{
	if(l%2==0)
		l++;
	if(r%2==0)
		r--;
	if(l>r)
		return 0;
	return 1 + (r-l)/2;
}

int even(int l, int r)
{
	if(l%2)
		l++;
	if(r%2)
		r--;
	if(l>r)
		return 0;
	return 1 + (r-l)/2;
}

int work(int val)
{
	int ans=1e18;
	auto it=s.lower_bound(val);
	if(it!=s.end())
		ans=min(ans, *it-val);
	if(it!=s.begin())
	{
		it--;
		ans=min(ans, val-*it);
	}
	return ans;
}	

int32_t main()
{
	IOS;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=(i%2)?a[i]:-a[i];
	}
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=m;i>=1;i--)
		sufB[i]=-b[i]-sufB[i+1];
	for(int i=1;i<=m-n+1;i++)
	{
		if(n%2)
			s.insert(sufB[i] + sufB[i+n]);
		else
			s.insert(sufB[i] - sufB[i+n]);
	}
	cout<<work(-sum)<<endl;
	while(q--)
	{
		int l, r, x;
		cin>>l>>r>>x;
		sum+=(odd(l, r) - even(l, r))*x;
		cout<<work(-sum)<<endl;
	}
	return 0;
}