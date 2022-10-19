#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[10];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=0;
        map<string,ll>mp;
        map<char,ll>mp1,mp2;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            mp[s]++;
            mp1[s[0]]++;
            mp2[s[1]]++;
        }
        for(auto pr:mp)
        {
            ans-=pr.second*(pr.second-1);
        }
        for(auto pr:mp1)
        {
            ans+=pr.second*(pr.second-1)/2;
        }
        for(auto pr:mp2)
        {
            ans+=pr.second*(pr.second-1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}