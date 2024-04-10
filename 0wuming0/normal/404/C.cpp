#include"bits/stdc++.h"
using namespace std;
int d[100005];
vector<int>v[100005];
int main()
{
    int n,k;
    cin>>n>>k;
    k--;
    for(int i=0;i<n;i++)
    {
        scanf("%d",d+i);
        v[d[i]].push_back(i+1);
    }
    if(v[0].size()!=1)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)if(k*(long long)v[i].size()+(i==0)<v[i+1].size())
    {
        cout<<-1<<endl;
        return 0;
    }
    vector<pair<int,int> >mp;
    for(int i=1;i<n;i++)
    {
        auto it=v[i-1].begin();
        for(auto u:v[i])
        {
            pair<int,int>pr;
            pr.first=*it;
            pr.second=u;
            mp.push_back(pr);
            it++;
            if(it==v[i-1].end())
            {
                it=v[i-1].begin();
            }
        }
    }
    cout<<mp.size()<<endl;
    for(auto pr:mp)
    {
        printf("%d %d\n",pr.first,pr.second);
    }
    return 0;
}