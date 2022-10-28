#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=4e5+5;

int n, m;
int a[N], pref[N], bit[2][N];

void update(int i, int idx, int val)
{
	idx+=2e5+1;
	while(idx<N)
	{
		bit[i][idx]+=val;
		idx+=(idx&-idx);
	}
}

int query(int i, int idx)
{
	idx+=2e5+1;
	int ans=0;
	while(idx>0)
	{
		ans+=bit[i][idx];
		idx-=(idx&-idx);
	}
	return ans;
}

int work(int k)
{
	int ans=0;
	memset(bit, 0, sizeof(bit));
	update(0, 0, 1);
	for(int i=1;i<=n;i++)
	{
		pref[i]=pref[i-1] + ((a[i]>=k)?1:-1);
		ans+=query(!(i%2), pref[i]) + query((i%2), pref[i]-1);
		update(i%2, pref[i], 1);
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=work(m) - work(m+1);
	cout<<ans;
	return 0;
}