#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=25;

int n, v;
int a[N], b[N];
double sum=0;
double maxx=1e9;

int32_t main()
{
	IOS;
	cin>>n>>v;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		maxx=min(maxx, (double)b[i]/a[i]);
	}
	maxx=min(maxx, v/sum);
	cout<<fixed<<setprecision(12)<<maxx*sum;
	return 0;
}