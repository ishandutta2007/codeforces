#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	double res=0.0;
	for(int o=k;o<=n;o++)
    {
        int sum=0;
        for(int i=0;i<o;i++) sum+=a[i];
        res=max(res,(double)sum/o);
        for(int i=o;i<n;i++)
        {
            sum-=a[i-o];
            sum+=a[i];
            res=max(res,(double)sum/o);
        }
    }
    printf("%.9f\n",res);
	return 0;
}