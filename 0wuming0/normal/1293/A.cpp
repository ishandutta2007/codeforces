#include"bits/stdc++.h"
using namespace std;
int n,s,k;int nn;
int p[1005]={0};
int findd(int tt)
{
    for(int i=0;i<k;i++)
        if(p[i]==tt)return 0;
    return 1;

}
void solve()
{

    for(int i=0;i<1005;i++)p[i]=0;
    for(int i=0;i<k;i++)
    {
        scanf("%d",p+i);
    }
    for(int i=0;;i++)
    {
        if(s-i>=1)if(findd(s-i))
                   {

            printf("%d\n",i);
            return;
        }
           if(s+i<=n)if(findd(s+i))
        {
            printf("%d\n",i);
            return;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&s,&k);
        solve();
    }

    return 0;
}