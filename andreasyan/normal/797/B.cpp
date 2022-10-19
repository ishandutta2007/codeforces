#include <bits/stdc++.h>
using namespace std;

int n;
int ans;

int main()
{
    cin>>n;
    vector<int> a;
    while(n--)
    {
        int x;
        cin>>x;
        if(x%2==0)
        {
            if(x>0)
                ans+=x;
        }
        else
            a.push_back(x);
    }
    sort(a.begin(),a.end());
    ans+=a.back();
    a.pop_back();
    int x=0;
    for(int i=a.size()-1;i>=0;--i)
        if(a[i]>0)
            ++x;
    if(x%2==0)
    {
        for(int i=a.size()-1,j=0;i>=0 && j<x;--i,++j)
            ans+=a[i];
    }
    else
    {
        for(int i=a.size()-1,j=0;i>=0 && j<(x-1);--i,++j)
            ans+=a[i];
        if(a.size()!=x)
        {
            if(a[a.size()-x]+a[a.size()-x-1]>0)
                ans+=(a[a.size()-x]+a[a.size()-x-1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}