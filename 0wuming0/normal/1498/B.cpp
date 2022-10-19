#include"bits/stdc++.h"
using namespace std;
#define gcd __gcd
multiset<int>s;
int w;
void solve()
{
    int now=w;
    while(1)
    {
        auto it=s.lower_bound(-now);
        if(it==s.end())break;
        now+=*it;
        s.erase(it);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>w;
        for(int i=0;i<n;i++)
        {
            int c;
            scanf("%d",&c);
            s.insert(-c);
        }
        int ans=0;
        while(s.size())
        {
            ans++;
            solve();
        }
        cout<<ans<<endl;
        //
    }
    return 0;
}