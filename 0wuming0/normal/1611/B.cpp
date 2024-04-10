#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n<m)swap(n,m);
        if(n-m>=2*m)printf("%d\n",m);
        else printf("%d\n",(n+m)/4);
    }
    return 0;
}