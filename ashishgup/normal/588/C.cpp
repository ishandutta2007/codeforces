#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v(n);
    int max=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]>max)
        {
            max=v[i];
        }
    }
    max+=1000;
    vector<int> v2(max+1,0);
    for(int i=0;i<n;i++)
    {
        v2[v[i]]++;
    }
    long long ans=0;
    for(int i=0;i<=max;i++)
    {
        if(v2[i]%2!=0)
        {
            ans++;
        }
        v2[i+1]+=v2[i]/2;
    }
    cout<<ans;
    return 0;
}