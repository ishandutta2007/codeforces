#include"bits/stdc++.h"
using namespace std;
int t[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int p,q;
        scanf("%d",&q);
        scanf("%d",&p);
        t[i]=q*p;
    }
    int sum=t[1],now=1;
    while(m--)
    {
        int q;
        scanf("%d",&q);
        while(q>sum)
        {
            now++;
            sum+=t[now];
        }
        printf("%d\n",now);
    }
    return 0;
}