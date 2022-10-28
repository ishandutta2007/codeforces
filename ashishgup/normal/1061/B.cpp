#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, reqd=0, total=0, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		total+=a[i];
	}
	sort(a+1, a+n+1);
	reqd=0;
	int prev=0;
	for(int i=1;i<=n;i++)
	{
		reqd+=1;
		if(a[i]>prev)
			prev++;
	}
	reqd+=(a[n]-prev);
	ans=total-reqd;
	cout<<ans;
	return 0;
}