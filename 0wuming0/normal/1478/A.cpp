#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            mp[a]++;
        }
        int ans=0;
        for(auto pr:mp)ans=max(ans,pr.second);
        cout<<ans<<endl;
    }
    return 0;
}