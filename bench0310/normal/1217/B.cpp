#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        int m=0;
        int d=0;
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            m=max(m,a);
            d=max(d,a-b);
        }
        if(d==0&&x>m) printf("-1\n");
        else if(m>=x) printf("1\n");
        else printf("%d\n",(x-m+d-1)/d+1);
    }
	return 0;
}