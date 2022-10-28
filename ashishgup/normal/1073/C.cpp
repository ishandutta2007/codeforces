#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
string s;
int x, y;
int up[N], rght[N];

int check(int L)
{
	for(int i=1;i+L-1<=n;i++)
	{
		int remup=up[i-1] + up[n] - up[i+L-1];
		int remr=rght[i-1] + rght[n] - rght[i+L-1];
		int reqdu=abs(x-remup);
		int reqdr=abs(y-remr);
		if(reqdu+reqdr<=L && (L - (reqdu+reqdr))%2==0)
			return 1;
	}
	return 0;
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
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		up[i+1]=up[i];
		rght[i+1]=rght[i];
		if(s[i]=='U')
			up[i+1]++;
		else if(s[i]=='D')
			up[i+1]--;
		else if(s[i]=='L')
			rght[i+1]--;
		else if(s[i]=='R')
			rght[i+1]++;
	}
	cin>>y>>x;
	if(up[n]==x && rght[n]==y)
	{
		cout<<"0";
		return 0;
	}
	int ans=binsearch(1, n);
	if(check(ans))
		cout<<ans;
	else
		cout<<"-1";
	return 0;
}