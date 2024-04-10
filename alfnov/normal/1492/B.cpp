#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int tot=0,wz=0;
		for(int i=1;i<=n;i++)if(a[i]>wz)b[++tot]=i,wz=a[i];
		b[tot+1]=n+1;
		int m=0;
		for(int i=tot;i>=1;i--)for(int j=b[i];j<b[i+1];j++)c[++m]=a[j];
		for(int i=1;i<=n;i++)printf("%d ",c[i]);
		puts("");
	}
	return 0;
}