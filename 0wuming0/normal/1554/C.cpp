#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int d=(1<<30);
        int ans=0;
        while(1)
        {
            if(d==0)
            {
                ans++;
                break;
            }
            if(m==d*2-1)
            {
                ans+=d*2;
                break;
            }
            if((m&d)&&(n&d)==0)
            {
                ans+=d;
                m-=d;
            }
            else if((m&d)&&(n&d))
            {
                m-=d;
            }
            else if((m&d)==0&&(n&d))
            {
                break;
            }
            d>>=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}