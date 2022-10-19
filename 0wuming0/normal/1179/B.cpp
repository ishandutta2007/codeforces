#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1,j=n;i<=j;i++,j--)
    {
        if(i==j)
        {
            for(int l=1,r=m;l<=r;l++,r--)
            {
                if(l!=r)
                {
                    printf("%d %d\n",i,l);
                    printf("%d %d\n",i,r);
                }
                else
                {
                    printf("%d %d\n",i,l);
                }
            }
        }
        else
        {
            for(int k=1;k<=m;k++)
            {
                printf("%d %d\n",i,k);
                printf("%d %d\n",j,m-k+1);
            }
        }
    }
    return 0;
}