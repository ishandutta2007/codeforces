#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    deque<int> d;
    int m=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        m=max(m,a);
        d.push_back(a);
    }
    vector<pair<int,int>> res;
    while(d.front()!=m)
    {
        int a=d.front();
        d.pop_front();
        int b=d.front();
        d.pop_front();
        res.push_back({a,b});
        d.push_front(max(a,b));
        d.push_back(min(a,b));
    }
    long long lim=res.size();
    d.pop_front();
    for(int i=0;i<q;i++)
    {
        long long now;
        scanf("%I64d",&now);
        if(now<=lim) printf("%d %d\n",res[now-1].first,res[now-1].second);
        else printf("%d %d\n",m,d[(now-lim-1)%(n-1)]);
    }
    return 0;
}