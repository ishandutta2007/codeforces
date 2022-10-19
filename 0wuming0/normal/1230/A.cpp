#include"bits/stdc++.h"
using namespace std;
int main()
{
    int a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    int s=a[0]+a[1]+a[2]+a[3];
    for(int i=0;i<16;i++)
    {
        int k=0;
        for(int j=0;j<4;j++)
        {
            if((1<<j)&i)k+=a[j];
        }
        if(k*2==s)
        {
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
}