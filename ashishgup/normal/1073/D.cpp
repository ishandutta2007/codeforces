#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, t, cnt=0, sum=0, ans=0;
int a[N], bit[2][N]; //0=sum, 1=alive

void update(int i, int idx, int k)
{
	while(idx<=n)
	{
		bit[i][idx]+=k;
		idx+=idx&-idx;
	}
}

int pref(int i, int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[i][idx];
		idx-=idx&-idx;
	}
	return ans;
}

int check(int x)
{
	int cursum=pref(0, x);
	return cursum>t;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(0, i, a[i]);
		update(1, i, 1);
	}
	while(pref(1, n)>0)
	{
		cnt=pref(1, n);
		sum=pref(0, n);
		ans+=(t/sum)*cnt;
		t%=sum;
		int idx=binsearch(1, n);
		update(0, idx, -a[idx]);
		update(1, idx, -1);
	}
	cout<<ans;
	return 0;
}