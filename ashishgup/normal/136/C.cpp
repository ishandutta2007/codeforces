#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	if(a[n]!=1)
		a[n]=1;
	else
		a[n]=2;
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}