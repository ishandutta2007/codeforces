#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    map<int,int>mp;
    for(int i=1;;i++)
    {
        if(i*(i+1)/2*3-i>1e9+1)break;
        mp[i*(i+1)/2*3-i]=i;
    }
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        while(1)
        {
            auto it=mp.upper_bound(n);
            if(it==mp.begin())break;
            ans++;
            it--;
            n-=it->first;
        }
        cout<<ans<<endl;
    }
    return 0;
}