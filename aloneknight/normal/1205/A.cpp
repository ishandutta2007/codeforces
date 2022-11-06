#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,a[N];
int main()
{
	scanf("%d",&n);int m=2*n;
	ll r=1ll*m*(m+1)/2;
	if(r%2==0){puts("NO");return 0;}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			a[i]=i*2-1;
			a[i+n]=i*2;
		}
		else
		{
			a[i]=i*2;
			a[i+n]=i*2-1;
		}
	}
	for(int i=1;i<=2*n;i++)printf("%d ",a[i]);
	return 0;
}