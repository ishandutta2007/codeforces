#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false);
using namespace std;

int main()
{
    IOS
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    if(n==1)
    {
        if(v[0]==0||v[0]==15)
        {
            if(v[0]==0)
            {
                cout<<"UP";
            }
            else
            {
                cout<<"DOWN";
            }
        }
        else
        {
            cout<<"-1";
        }
        return 0;
    }
    if(v[n-1]==15)
    {
        cout<<"DOWN";
        return 0;
    }
    if(v[n-1]==0)
    {
        cout<<"UP";
        return 0;
    }
    if(v[n-1]>v[n-2])
    {
        cout<<"UP";
    }
    else
    {
        cout<<"DOWN";
    }
    
    
    return 0;
}