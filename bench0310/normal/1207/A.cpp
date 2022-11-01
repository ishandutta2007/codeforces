#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int b,p,f;
        int h,c;
        scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
        int res=0;
        if(h>=c)
        {
            int n=min(b/2,p);
            res+=h*n;
            b-=2*n;
            n=min(b/2,f);
            res+=c*n;
        }
        else
        {
            int n=min(b/2,f);
            res+=c*n;
            b-=2*n;
            n=min(b/2,p);
            res+=h*n;
        }
        printf("%d\n",res);
    }
	return 0;
}