#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1, b+n+1);
	int ct=0;
	for(int i=1;i<=n;i++)
		ct+=(b[i]!=a[i]);
	if(ct<=2)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}