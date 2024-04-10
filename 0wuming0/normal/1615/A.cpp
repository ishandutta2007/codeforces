#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        if(sum%n==0)printf("0\n");
        else printf("1\n");
    }
    return 0;
}