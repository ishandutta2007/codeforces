#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[1005][1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	ll t=(ll)(sqrt((long double)a[1][2])*sqrt((long double)a[1][3])*sqrt((long double)a[2][3])+0.5);
	int a1=t/a[2][3];printf("%d ",a1);
	for(int i=2;i<=n;i++)printf("%d ",a[1][i]/a1);
	return 0;
}