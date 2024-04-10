#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        multiset<int>v;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            ans+=a/k;
            v.insert(a%k);
        }
        while(v.size())
        {
            auto it=v.end();
            it--;
            int a=*it;
            v.erase(it);
            it=v.lower_bound(k-a);
            if(it==v.end())break;
            else
            {
                v.erase(it);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}