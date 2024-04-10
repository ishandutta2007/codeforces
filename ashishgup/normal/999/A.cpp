#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1;
	while(l<=n && a[l]<=k)
		l++;
	int r=n;
	while(r>=1 && a[r]<=k)
		r--;
	int ans=n - max(0LL, r-l+1);
	cout<<ans;   
	return 0;   
}