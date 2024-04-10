#include<bits/stdc++.h>
using namespace std;
int n,ans,b;
char a[1000];
int main()
{
	cin>>n;
	scanf("%s",a+1);
	ans=n;
	for (int i=1;i<n;++i)
	{
		if (a[i]!=a[i+1]&&!b)
		{
			--ans;
			b=1;
		}
		else
			b=0;
	}
	cout<<ans;
	return 0;
}