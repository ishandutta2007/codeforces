#include"bits/stdc++.h"
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2)
        {
        int flag=2;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%1d",&a);
            if((a%2)&&(i%2))flag=1;
        }
        printf("%d\n",flag);
        }
        else
        {
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%1d",&a);
            if((a%2)==0&&(i%2)==0)flag=2;
        }
        printf("%d\n",flag);
        }

    }
    return 0;
}
/*
1
4
1221
*/