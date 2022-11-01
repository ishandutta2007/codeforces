#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v(n+1,0);
        for(int i=1;i<=n;i++) scanf("%d",&v[i]);
        vector<vector<int>> sum(n+1,vector<int>(201,0));
        vector<vector<int>> x(201);
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1];
            sum[i][v[i]]++;
            x[v[i]].push_back(i);
        }
        auto midfix=[&](int l,int r)->int
        {
            if(l>r) return 0;
            int m=0;
            for(int i=1;i<=200;i++) m=max(m,sum[r][i]-sum[l-1][i]);
            return m;
        };
        int res=midfix(1,n);
        for(int i=1;i<=200;i++)
        {
            int l=0;
            int r=x[i].size()-1;
            while(l<r)
            {
                res=max(res,2*(l+1)+midfix(x[i][l]+1,x[i][r]-1));
                l++;
                r--;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}