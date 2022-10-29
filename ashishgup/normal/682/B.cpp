#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    if(n==1)
    {
        cout<<2;
        return 0;
    }
    if(n==2)
    {
        if(v[1]==1)
        {
            cout<<2;
        }
        else
        {
            cout<<3;
        }
        return 0;
    }
    int k=2;
    v[0]=1;
    int index=1;
    while(index<n-1)
    {
        if(v[index]==k-1)
        {
            index++;
            continue;
        }
        ll up=upper_bound(v.begin()+index,v.end(),k)-v.begin();
        ll low=lower_bound(v.begin()+index,v.end(),k)-v.begin();
        if(up!=low)
        {
            k++;
            index++;
            continue;
        }
        v[index]=k;
        k++;
        index++;
    }
    if(v[n-1]>v[n-2])
    {
        v[n-1]=v[n-2]+1;
    }
    cout<<v[n-1]+1;
    return 0;
}