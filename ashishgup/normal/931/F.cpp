#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N], ct[N], bit[N], forwrd[N], backward[N];

void update(int idx, int val)
{
	idx+=1;
	while(idx<=m+1)
	{
		bit[idx]=max(bit[idx], val);
		idx+=(idx&(-idx));
	}
}

int prefmax(int idx)
{
	idx+=1;
	int ans=0;
	while(idx>0)
	{
		ans=max(ans, bit[idx]);
		idx-=(idx&(-idx));
	}
	return ans;
}

int work()
{
	for(int i=1;i<=m;i++)
	{
		forwrd[i]=prefmax(ct[i])+1;
		update(ct[i], forwrd[i]);
	}
	memset(bit, 0, sizeof(bit));
	reverse(ct+1, ct+m+1);
	for(int i=1;i<=m;i++)
	{
		backward[i]=prefmax(ct[i])+1;
		update(ct[i], backward[i]);
	}
	reverse(backward+1, backward+m+1);
	int ans=0;
	for(int i=1;i<=m;i++)
		ans=max(ans, forwrd[i]+backward[i]-1);
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int l, r;
		cin>>l>>r;
		ct[l]+=1;
		ct[r+1]-=1;
	}
	for(int i=1;i<=m;i++)
		ct[i]+=ct[i-1];
	int ans=work();
	cout<<ans;
	return 0;
}