#include"bits/stdc++.h"
using namespace std;
int main()
{
    int d;
    cin>>d;
    int t;
    cin>>t;
    int a[50],b[50];int sa=0,sb=0;
    for(int i=1;i<=d;i++)
    {
        scanf("%d%d",a+i,b+i);
        sa+=a[i];sb+=b[i];
    }
    if(sa>t||sb<t)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=d;i++)
        {
            sa-=a[i];
            sb-=b[i];
            for(int j=a[i];j<=b[i];j++)
            {
                if(sa<=t-j&&t-j<=sb)
                {
                    t-=j;
                    printf("%d%c",j," \n"[i==d]);
                    break;
                }
            }
        }
    }
    return 0;
}