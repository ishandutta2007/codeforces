#include<bits/stdc++.h>
using namespace std;
int m;
double n,a,b,ans=1e9;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a>>b,ans=min(ans,a/b);
	printf("%.8lf",m*ans);
    return 0;
}