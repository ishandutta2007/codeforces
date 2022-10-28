#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, idx=1, cur=1e6-1, lim=1e6, added=0;
int a[N], rem[N], reqd[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<n+1<<endl;
	cout<<1<<" "<<n<<" "<<cur-a[n]<<endl;
	added+=cur-a[n];
	for(int i=n-1;i>=1;i--)
	{
		int shouldbe=lim-1-idx++;
		int is=(a[i]+added)%lim;
		int diff=(shouldbe-is+lim)%lim;
		added+=diff;
		cout<<1<<" "<<i<<" "<<diff<<endl;
	}
	cout<<2<<" "<<n<<" "<<lim<<endl;
	return 0;
}