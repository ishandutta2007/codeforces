#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n, m, k;
	cin>>n>>m>>k;
	k++;
	if(k<=n)
	{
		cout<<k<<" "<<1;
		return 0;
	}
	k-=n;
	int row=n - (k-1)/(m-1);
	int rem=(k-1)%(m-1);
	int col=0;
	if(row%2==0)
		col=2+rem;
	else
		col=m-rem;
	cout<<row<<" "<<col;
	return 0;
}