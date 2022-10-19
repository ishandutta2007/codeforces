#include"bits/stdc++.h"
using namespace std;
#define ll long long
vector<ll>v[100];
vector<ll>save;
int main()
{
    int best=-1,ans=0;
    int n;
    cin>>n;
    for(int j=0;j<n;j++)
    {
        ll c;
        scanf("%lld",&c);
        for(int i=1;i<=62;i++)
        {
            if(c%(1ll<<i)==(1ll<<(i-1)))
            {
                v[i].push_back(c);
            }
        }
    }
    for(int i=1;i<=62;i++)if(v[i].size()>ans)
    {
        ans=v[i].size();
        best=i;
    }
    for(int i=1;i<=62;i++)if(i!=best)
    {
        for(auto a:v[i])save.push_back(a);
    }
    sort(save.begin(),save.end());
    cout<<save.size()<<endl;
    for(auto it:save)
    {
        printf("%lld ",it);
    }
    return 0;
}