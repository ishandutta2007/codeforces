#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, a, b;
int s[N];

int check(int idx)
{
	int total=0;
	for(int i=1;i<idx;i++)
		total+=s[i];
	int lhs=s[1]*a;
	int rhs=total*b;
	return lhs>=rhs;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+2, s+n+1);
	int ans=binsearch(2, n+1);
	cout<<(n+1-ans);	
	return 0;
}