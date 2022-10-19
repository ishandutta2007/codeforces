#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        scanf("%d%d",&a,&b);
        if((a+b)%2)printf("-1\n");
        else if(a+b==0)printf("0\n");
        else if(a==b)printf("1\n");
        else printf("2\n");
        {

        }
    }
    return 0;
}