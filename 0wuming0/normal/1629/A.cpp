#include"bits/stdc++.h"
using namespace std;
int a[105],b[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        multimap<int,int>mp;
        mp.insert(pair<int,int>(1e9,0));
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            mp.insert(pair<int,int>(a[i],b[i]));
        }
        while(1)
        {
            if(mp.begin()->first>k)break;
            k+=mp.begin()->second;
            mp.erase(mp.begin());
        }
        cout<<k<<endl;
    }
    return 0;
}