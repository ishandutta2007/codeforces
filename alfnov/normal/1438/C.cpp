#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
		{
		    for(int j=1;j<=m;j++)
    		{
    		    if((i+j)&1)printf("%d ",a[i][j]+(a[i][j]&1));
    		    else printf("%d ",a[i][j]+!(a[i][j]&1));
    		}
    		puts("");
		}
	}
	return 0;
}