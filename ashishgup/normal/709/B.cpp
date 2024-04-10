#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, a;
int x[N];

int work(int p, int q)
{
	int dist=abs(a-x[p]) + abs(x[p]-x[q]);
	return dist;
}

int32_t main()
{
	IOS;
	cin>>n>>a;
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>x[i];
	sort(x+1, x+n+1);
	int ans=min(work(1, n-1), work(2, n));
	ans=min(ans, min(work(n-1, 1), work(n, 2)));
	cout<<ans;
}