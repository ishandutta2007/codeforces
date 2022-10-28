#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, s, sum=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int othersmin=n-1;
		int curmax=s - othersmin;
		int curans=max(0LL, (a[i] - curmax));
		int othersmax=sum-a[i];
		int curmin=s - othersmax;
		curans+=max(0LL, curmin-1);
		cout<<curans<<" ";
	}
	return 0;
}