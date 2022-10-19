#include"bits/stdc++.h"
using namespace std;
int c[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",c+i);
            if(c[i]==0)a++;
            if(c[i]!=0)b=1;
        }
        if(b==0)printf("0\n");
        else if(a==0)printf("1\n");
        else
        {
            for(int i=0;i<n;i++)if(c[i]==0)a--;
                else break;
            for(int i=n-1;i;i--)if(c[i]==0)a--;
                else break;
            if(a==0)printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}