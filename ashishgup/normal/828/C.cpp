#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e6+5;

int n, lastidx=0;
int bit[N]; //marked or not
char ans[N];

void update(int idx, int val)
{
	while(idx<N)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

int check(int val, int idx)
{	
	return pref(idx) > val;
}

int binsearch(int val, int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(val, mid))
			hi=mid;
		else
			lo=mid+1;
	}
	if(!check(val, lo))
		lo=-1;
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<N;i++)
	{
		ans[i]='a';
		update(i, 1);
	}
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int len=s.size();
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int idx;
			cin>>idx;
			lastidx=max(lastidx, idx+len-1);
			int cur;
			while((cur = binsearch(pref(idx-1), idx, idx+len-1)) != -1)
			{
				ans[cur]=s[cur-idx];
				update(cur, -1);
			} 
		}	
	}
	for(int i=1;i<=lastidx;i++)
		cout<<ans[i];
	return 0;
}