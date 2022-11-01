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
        bool one=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            m=max(m,a);
            if(a==x) one=1;
        }
        int res=0;
        if(one) res=1;
        else if(m>x) res=2;
        else if((x%m)==0) res=(x/m);
        else res=(x/m)+1;
        printf("%d\n",res);
    }
    return 0;
}