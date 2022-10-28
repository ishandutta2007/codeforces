#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
long double ans=0, sum=0;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		sum+=a[i];
	}
	for(int i=n;i>=1;i--)
	{
		int cur=a[i]*(i-1);
		sum-=a[i];
		m[a[i]]--;
		cur-=sum;
		int adjust=0;
		for(int j=a[i]-1;j<=a[i]+1;j++)
		{
			adjust-=m[j]*a[i];
			adjust+=m[j]*j;
		}
		cur+=adjust;
		ans+=cur;
	}
	cout<<fixed<<setprecision(0)<<ans;
	return 0;
}