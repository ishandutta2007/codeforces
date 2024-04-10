#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;

int n, k;
int a[N];

int32_t main()
{
	IOS;	
	cin>>n>>k;
	if(n<3*k)
	{
		cout<<"-1";
		return 0;
	}
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=cur++;
		cur%=k;
	}
	rotate(a+1, a+2, a+k+1);
	for(int i=1;i<=n;i++)
		cout<<a[i]+1<<" ";
	return 0;
}