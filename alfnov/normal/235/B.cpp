#include<bits/stdc++.h>
using namespace std;
double x1[100005],x2[100005],p[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++)
	{
		x1[i]=p[i]*(x1[i-1]+1);
		x2[i]=x2[i-1]+p[i]*(2*x1[i-1]+1);
	}
	printf("%.6f\n",x2[n]);
	return 0;
}