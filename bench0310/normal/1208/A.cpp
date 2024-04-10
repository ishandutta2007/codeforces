#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        if((t%3)==0) printf("%d\n",a);
        else if((t%3)==1) printf("%d\n",b);
        else printf("%d\n",a^b);
    }
	return 0;
}