#include"bits/stdc++.h"
using namespace std;
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        long long s=0;
        for(int i=1;i<=n;i++)s+=a[i]-1;
        if(s%2)printf("errorgorn\n");
        else printf("maomao90\n");
    }
    return 0;
}