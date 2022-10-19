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
        set<int>s;
        for(int i=1;i<=n;i++)s.insert(i);
        while(m--)
        {
            int k;
            scanf("%*d%d%*d",&k);
            if(s.find(k)!=s.end())s.erase(s.find(k));
        }
        for(int i=1;i<=n;i++)if(i!=*s.begin())printf("%d %d\n",i,*s.begin());
    }
    return 0;
}