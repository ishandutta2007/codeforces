#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, sum=0, reqd=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cur=(a[i]+k-1)/k;
		reqd+=cur;
		int tot=cur*k;
		tot-=a[i];
		a[i+1]-=tot;
		a[i+1]=max(a[i+1], 0LL);
	}	
	cout<<reqd;
	return 0;
}