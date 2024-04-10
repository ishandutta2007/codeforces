#include"bits/stdc++.h"
using namespace std;
int num[500];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n%2==0)printf("%d %d 1\n",n/2-1,n/2);
        else if(n%4==1)printf("%d %d 1\n",n/2-1,n/2+1);
        else if(n%4==3)printf("%d %d 1\n",n/2-2,n/2+2);
    }
    return 0;
}