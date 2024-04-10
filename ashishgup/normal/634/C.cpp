#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, a, b, q, sum=0;
int d[N];
int bit[3][N];

void update(int i, int idx, int k)
{
	if(i==1)
		idx=n-idx+1;
	while(idx<=n)
	{
		bit[i][idx]+=k;
		idx+=idx&-idx;
	}
}

int pref(int i, int idx)
{
	int ans=0;
	if(i==1)
		idx=n-idx+1;
	while(idx>0)
	{
		ans+=bit[i][idx];
		idx-=idx&-idx;
	}
	return ans;
}

int rsum(int i, int l, int r)
{
	return pref(i, r) - pref(i, l-1);
}

int32_t main()
{
	IOS;
	cin>>n>>k>>a>>b>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int day, x;
			cin>>day>>x;
			sum+=x;
			update(2, day, x);
			int prev=d[day];
			d[day]+=x;
			int diff=max(0LL, d[day]-max(prev, b));
			update(0, day, diff);
			diff=max(0LL, d[day]-max(prev, a));
			update(1, day, diff);
		}
		else
		{
			int x;
			cin>>x;
			int ans=sum - pref(0, x-1) - pref(1, x+k) - rsum(2, x, x+k-1);
			cout<<ans<<endl;
		}
	}
	return 0;
}