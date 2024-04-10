#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        long long y;
        int k=0;
        scanf("%d%d%lld",&n,&x,&y);
        k^=(x&1)^(y&1);
        while(n--)
        {
            scanf("%d",&x);
            k^=(x&1);
        }
        if(k==0)printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}