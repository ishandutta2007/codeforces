#include"bits/stdc++.h"
using namespace std;
int ans[200005][20];
int main()
{
    for(int i=0;i<200005;i++)for(int j=0;j<20;j++)
    {
        if(i&(1<<j))ans[i][j]=1;
        if(i)ans[i][j]+=ans[i-1][j];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int anss=1e9;
        for(int j=0;j<20;j++)
        {
            anss=min(r-l+1-(ans[r][j]-ans[l-1][j]),anss);
            ;
        }
        printf("%d\n",anss);
    }
    return 0;
}