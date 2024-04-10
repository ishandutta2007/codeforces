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
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	reverse(a+1, a+n+1);
	reverse(b+1, b+n+1);
	int i=1, j=1, player=0, moves=0, asum=0, bsum=0;
	while(moves<2*n)
	{
		moves++;
		if(!player)
		{
			if(a[i]>=b[j])
			{
				asum+=a[i];
				i++;
			}
			else
				j++;
		}
		else
		{
			if(b[j]>=a[i])
			{
				bsum+=b[j];
				j++;
			}
			else
				i++;
		}
		player^=1;
	}
	cout<<asum-bsum;
	return 0;
}