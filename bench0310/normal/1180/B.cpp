#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int m=0,id;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=0) a[i]=-a[i]-1;
        if(a[i]<m)
        {
            m=a[i];
            id=i;
        }
    }
    if(n&1) a[id]=-a[id]-1;
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
	return 0;
}