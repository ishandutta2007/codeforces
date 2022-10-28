#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int k, n;
string s;
int store[N];

int check(int sz)
{
	int idx=0, len=0, rows=1;
	while(idx<n)
	{
		int cursz=store[idx]-idx+1;
		if(cursz>sz)
			return 0;
		if(cursz+len>sz)
		{
			len=0;
			rows++;
			continue;
		}
		len+=cursz;
		idx=store[idx]+1;
	}
	return rows<=k;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
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
	cin>>k;
	cin.ignore();
	getline(cin, s);
	n=s.size();
	store[n-1]=n-1;
	for(int i=n-2;i>=0;i--)
	{
		store[i]=store[i+1];
		if(s[i]=='-' || s[i]==' ')
			store[i]=i;
	}
	int ans=binsearch(1, s.size());
	cout<<ans;
	return 0;
}