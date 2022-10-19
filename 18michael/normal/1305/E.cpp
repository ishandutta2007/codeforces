#include<bits/stdc++.h>
using namespace std;
int n,m,t=1;
int a[5002];
int main()
{
	for(scanf("%d%d",&n,&m);t<=n && m>=(t-1)/2;++t)a[t]=t,m-=(t-1)/2;
	if(t>n && m)return 0&puts("-1");
	if(m)a[t]=2*t-2*m-1,++t;
	for(;t<=n;++t)a[t]=n*n+t*n;
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}