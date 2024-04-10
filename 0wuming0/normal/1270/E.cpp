#include"bits/stdc++.h"
using namespace std;
int x[1005],y[1005];
int n;
bool solve4()
{
    for(int i=1;i<=n;i++)y[i]++;
    for(int i=1;i<=n;i++)if(x[i]%2||y[i]%2)return 0;
    for(int i=1;i<=n;i++)x[i]/=2,y[i]/=2;
    return 1;
}
bool solve3()
{
    for(int i=1;i<=n;i++)x[i]++;
    for(int i=1;i<=n;i++)if(x[i]%2||y[i]%2)return solve4();
    for(int i=1;i<=n;i++)x[i]/=2,y[i]/=2;
    return 1;
}
bool solve2()
{
    for(int i=1;i<=n;i++)y[i]--;
    for(int i=1;i<=n;i++)if(x[i]%2||y[i]%2)return solve3();
    for(int i=1;i<=n;i++)x[i]/=2,y[i]/=2;
    return 1;
}
bool solve()
{
    for(int i=1;i<=n;i++)if(x[i]%2||y[i]%2)return solve2();
    for(int i=1;i<=n;i++)x[i]/=2,y[i]/=2;
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    while(solve());
    vector<int>v;
    for(int i=1;i<=n;i++)if((x[i]+y[i])%2)v.push_back(i);
    if(v.size()==0||v.size()==n)
    {
        v.clear();
        for(int i=1;i<=n;i++)if(x[i]%2)v.push_back(i);
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)printf("%d%c",v[i]," \n"[i==v.size()-1]);
    return 0;
}