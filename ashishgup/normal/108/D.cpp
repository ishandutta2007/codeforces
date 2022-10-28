#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int tot, rem, n, m, h;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>h;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	a[h]--;
	n--;
	for(int i=1;i<=m;i++)
		tot+=a[i];
	rem=tot-a[h];
	double num=1, den=1;
	if(tot<n)
	{
		cout<<"-1";
		return 0;
	}
	double ans;
	if(rem<n)
	{
		ans=1;
	}
	else
	{
		for(int i=rem-n+1;i<=rem;i++)
			num*=i;
		for(int i=tot-n+1;i<=tot;i++)
			den*=i;
		ans=1 - (num/den);
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}