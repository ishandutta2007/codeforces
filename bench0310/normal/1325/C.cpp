#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<array<int,2>> v[n+1];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    vector<int> x;
    for(int i=1;i<=n;i++) if(v[i].size()==1) x.push_back(i);
    if(x.size()==2) for(int i=0;i<n-1;i++) printf("%d\n",i);
    else
    {
        vector<int> res(n-1,-1);
        for(int i=0;i<3;i++) res[v[x[i]][0][1]]=i;
        int now=3;
        for(int i=0;i<n-1;i++) if(res[i]==-1) res[i]=now++;
        for(int i=0;i<n-1;i++) printf("%d\n",res[i]);
    }
    return 0;
}