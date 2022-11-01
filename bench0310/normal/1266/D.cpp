#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<long long> v(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        long long d;
        scanf("%d%d%I64d",&a,&b,&d);
        v[a]-=d;
        v[b]+=d;
    }
    vector<int> one,two;
    for(int i=1;i<=n;i++)
    {
        if(v[i]>0) one.push_back(i);
        if(v[i]<0) two.push_back(i);
    }
    vector<tuple<int,int,long long>> res;
    int idx=0;
    for(int a:one)
    {
        while(v[a]>0)
        {
            long long t=min(v[a],-v[two[idx]]);
            if(t==0)
            {
                idx++;
                continue;
            }
            v[a]-=t;
            v[two[idx]]+=t;
            res.push_back(make_tuple(two[idx],a,t));
        }
    }
    printf("%d\n",(int)res.size());
    for(tuple<int,int,long long> t:res) printf("%d %d %I64d\n",get<0>(t),get<1>(t),get<2>(t));
    return 0;
}