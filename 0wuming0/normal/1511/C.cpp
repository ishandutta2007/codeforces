#include"bits/stdc++.h"
using namespace std;
int now[51];
int ans[300005],nn;
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        if(now[c]==0)now[c]=i;
    }
    while(q--)
    {
        int c;
        scanf("%d",&c);
        ans[nn++]=now[c];
        for(int i=1;i<=50;i++)
        {
            if(now[i]<now[c])now[i]++;
        }
        now[c]=1;
    }
    for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[nn-1==i]);
    return 0;
}