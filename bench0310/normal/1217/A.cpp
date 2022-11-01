#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int l=-1,r=c+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(a+m>b+c-m) r=m;
            else l=m;
        }
        printf("%d\n",c-r+1);
    }
	return 0;
}