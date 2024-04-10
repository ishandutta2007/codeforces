#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll add[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        map<ll,int>mp;
        for(int i=0;i<2*n;i++)
        {
            ll a;
            scanf("%lld",&a);
            mp[a]++;
        }
        vector<ll>v;
        for(auto pr:mp)
        {
            if(pr.first==0||pr.second!=2||(pr.first&1))
            {
                puts("no");
                goto ne;
            }
            v.push_back(pr.first);
        }
        for(ll i=1;i<n;i++)
        {
            ll pp=i*2;
            if((v[i]-v[i-1])%pp)
            {
                puts("no");
                goto ne;
            }
            add[i]=(v[i]-v[i-1])/pp;//cout<<"<<"<<i<<" "<<add[i]<<endl;
            add[i]+=add[i-1];
        }
        for(ll i=1;i<n;i++)add[i]+=add[i-1];
        if(v[0]-add[n-1]*2>0&&(v[0]-add[n-1]*2)%(2*n)==0)
            puts("yes");
        else
            puts("no");
        ne:;
    }
    return 0;
}
/*

*/