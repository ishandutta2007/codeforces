#include<bits/stdc++.h>
using namespace std;
double m,t,res,a[1005],b[1005];
int main()
{
	int n,ff=0;scanf("%d%lf",&n,&m);
	for(int i=0;i<n;i++){scanf("%lf",&a[i]);ff|=(a[i]<=1);}
	for(int i=0;i<n;i++){scanf("%lf",&b[i]);ff|=(b[i]<=1);}
	if(ff)puts("-1");
	else
	{
		t=m/(b[0]-1);m+=t;res+=t;
		for(int i=n-1;i>=0;i--)
		{
			t=m/(a[i]-1);m+=t;res+=t;
			if(i!=0){t=m/(b[i]-1);m+=t;res+=t;}
		}
		printf("%.10f\n",res);
	}
	return 0;
}