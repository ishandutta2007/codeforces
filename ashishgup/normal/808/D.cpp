#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, sum=0;
int a[N], pref[N];
map<int, int> prefix, suffix;

int getsum(int l, int r)
{
	if(l>=1)
		return pref[r] - pref[l-1];
	return pref[r];
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=a[i]+pref[i-1];
		suffix[a[i]]++;
	}
	int check=0;
	for(int i=0;i<=n;i++)
	{
		int lsum=getsum(0, i);
		int rsum=getsum(i+1, n);
		if(i>=1)
		{
			prefix[a[i]]++;
			suffix[a[i]]--;
		}
		int diff=lsum-rsum;
		if(diff==0)
			check=0;
		if(diff%2!=0)
			continue;
		int reqd=diff/2;
		if(reqd>0)
		{
			if(prefix[reqd]>0)
				check=1;
		}
		else
		{
			reqd*=-1;
			if(suffix[reqd]>0)
				check=1;
		}
	}
	if(check)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}