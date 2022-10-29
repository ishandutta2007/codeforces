#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, c, d, ans=0;
int bit[2][N];

void update(int i, int idx, int val)
{
	while(idx<=1e5)
	{
		bit[i][idx]=max(bit[i][idx], val);
		idx+=idx&-idx;
	}
}

int query(int i, int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans=max(ans, bit[i][idx]);
		idx-=idx&-idx;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>c>>d;
	for(int i=1;i<=n;i++)
	{
		int b, p;
		char ch;
		cin>>b>>p>>ch;
		if(ch=='C' && p<=c)
		{
			int other=max(query(0, c-p), query(1, d));
			if(other>0)
				ans=max(ans, other+b);
			update(0, p, b);
		}
		else if(ch=='D' && p<=d)
		{
			int other=max(query(0, c), query(1, d-p));
			if(other>0)
				ans=max(ans, other+b);
			update(1, p, b);
		}
	}	
	cout<<ans;
	return 0;
}