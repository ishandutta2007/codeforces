#include"bits/stdc++.h"
using namespace std;
vector<int>v[300005];
int num[300005],f[300005];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a;
            cin>>b;
            num[a]++;
            f[a]+=b;
        }
        for(int i=1;i<=n;i++)
        {
            if(num[i])
            {
                v[num[i]].push_back(f[i]);
            }
        }
        int ans=0,s=0;
        for(int i=n;i>=1;i--)if(v[i].size())
        {
            sort(v[i].begin(),v[i].end());
            ans+=i;
            s+=v[i][v[i].size()-1];
            v[i].pop_back();
            for(auto j:v[i])v[i-1].push_back(min(j,i-1));
        }
        cout<<ans<<" "<<s<<endl;
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            num[i]=f[i]=0;
        }
    }
    return 0;
}