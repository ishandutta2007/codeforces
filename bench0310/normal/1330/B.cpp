#include <bits/stdc++.h>

using namespace std;

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
        vector<bool> l(n+1,0);
        vector<bool> r(n+1,0);
        vector<bool> one(n+1,0);
        vector<bool> two(n+1,0);
        int now=1;
        for(int i=1;i<=n;i++)
        {
            l[v[i]]=1;
            while(l[now]) now++;
            one[i]=(now==i+1);
        }
        now=1;
        for(int i=n;i>=1;i--)
        {
            r[v[i]]=1;
            while(r[now]) now++;
            two[i]=(now==n-i+1+1);
        }
        vector<array<int,2>> res;
        for(int i=1;i<n;i++) if(one[i]&&two[i+1]) res.push_back({i,n-i});
        printf("%d\n",(int)res.size());
        for(auto [a,b]:res) printf("%d %d\n",a,b);
    }
    return 0;
}