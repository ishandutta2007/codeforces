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
        int d=min(min(a,b),c);
        a-=d;
        b-=d;
        c-=d;
        d+=min(min(a,b),(a+b)/3);
        printf("%d\n",d);
    }
	return 0;
}