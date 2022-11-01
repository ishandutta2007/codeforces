#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> sum(n+1,vector<int>(m+1,0));
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&sum[o][i]);
            sum[o][i]+=(sum[o-1][i]+sum[o][i-1]-sum[o-1][i-1]);
        }
    }
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    auto s=[&](int ar,int ac,int br,int bc)->int
    {
        return sum[br][bc]-sum[br][ac-1]-sum[ar-1][bc]+sum[ar-1][ac-1];
    };
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            res+=(multiset<int>{a,b,c}==multiset<int>{s(1,1,i,m),s(i+1,1,j,m),s(j+1,1,n,m)});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            res+=(multiset<int>{a,b,c}==multiset<int>{s(1,1,n,i),s(1,i+1,n,j),s(1,j+1,n,m)});
        }
    }
    printf("%d\n",res);
    return 0;
}