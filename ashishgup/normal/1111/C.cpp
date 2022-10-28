#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, A, B;
int a[N];

int get(int l, int r)
{
	auto it=lower_bound(a+1, a+k+1, l);
	auto it2=upper_bound(a+1, a+k+1, r);
	int sz=it2-it;
	return sz;
}

bool check(int l, int r)
{
	return get(l, r)>0;
}

int rec(int l, int r)
{
	if(!check(l, r))
		return A;
	if(l==r)
		return B*get(l, r);
	int m=(l+r)/2;
	int ans=min((r-l+1)*B*get(l, r), rec(l, m) + rec(m+1, r));
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>k>>A>>B;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	sort(a+1, a+k+1);
	int ans=rec(1, (1LL<<n));
	cout<<ans;
	return 0;
}