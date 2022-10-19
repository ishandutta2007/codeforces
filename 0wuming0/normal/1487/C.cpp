#include"bits/stdc++.h"
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
            for(int i=n-1;i>1;i--)
            {
                for(int j=0;j<i;j++)
                    printf("%d ",(j%2==0?-1:1));
            }
            printf("%d\n",-1);
        }
        else
        {
            for(int i=n-1;i>1;i--)
            {
                if(i%2)
                {
                    printf("%d ",0);
                    for(int j=1;j<i;j++)
                        printf("%d ",(j%2==0?-1:1));
                }
                else
                {
                    for(int j=0;j<i;j++)
                        printf("%d ",(j%2==0?-1:1));
                }
            }
            printf("%d\n",0);
        }
    }
    return 0;
}