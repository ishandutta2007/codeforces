#include<bits/stdc++.h>
using namespace std;
int a[10002],n,m,d,ans,h;
int main()
{
	cin>>n>>m>>d;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i*m+j];
	sort(a,a+n*m);
	for(int i=1;i<n*m;i++)
		if((a[i]-a[i-1])%d)cout<<-1,exit(0);
	h=a[(n*m)/2];
	for(int i=0;i<n*m;i++)
		ans+=abs(a[i]-h)/d;
	cout<<ans;
    return 0;
}