#include<bits/stdc++.h>
using namespace std;
const int N=10;
pair<int,int> a[N];
int x[N],y[N];
vector<pair<pair<int,int>,pair<int,int> > > ans;
inline void build(pair<int,int> a,pair<int,int> b)
{
    if (a.first!=b.first)
    {
        ans.push_back({a,{b.first,a.second}});
        a.first=b.first;
    }
    if (a.second!=b.second)
    {
        ans.push_back({a,b});
    }
}
int main()
{
    for (int i=1;i<=3;++i)
        scanf("%d%d",&a[i].first,&a[i].second);
    for (int i=1;i<=3;++i)
    {
        x[i]=a[i].first;
        y[i]=a[i].second;
    }
    sort(x+1,x+4);
    sort(y+1,y+4);
    for (int i=1;i<=3;++i)
        build(a[i],{x[2],y[2]});
    printf("%d\n",(int)ans.size());
    for (auto p:ans)
        printf("%d %d %d %d\n",p.first.first,p.first.second,p.second.first,p.second.second);
    return 0;
}