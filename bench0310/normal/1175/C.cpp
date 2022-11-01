#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        k++;
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int res=1000000000;
        int id;
        for(int i=0;i+k-1<n;i++)
        {
            if((a[i+k-1]-a[i]+1)/2<res)
            {
                res=(a[i+k-1]-a[i]+1)/2;
                id=(a[i]+a[i+k-1])/2;
            }
        }
        printf("%d\n",id);
    }
	return 0;
}