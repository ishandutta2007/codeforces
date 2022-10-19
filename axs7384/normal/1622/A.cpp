#include<bits/stdc++.h>
using namespace std;
int t,a[100];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		for (int i=1;i<=3;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+1+3);
		puts(((a[3]==a[1]+a[2])||(a[1]==a[2]&&a[3]%2==0)||(a[2]==a[3]&&a[1]%2==0))?"YES":"NO");
	}
	return 0;
}