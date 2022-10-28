#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j+1<=n && a[j+1]==a[i])
			j++;
		int len=(j-i+1);
		ans+=len*(len+1)/2;
		i=j;
	}
	cout<<ans;
	return 0;
}