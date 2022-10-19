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
        map<int,int>mp;int c;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&c);
            mp[c]++;
        }
        auto it=mp.begin();
        cout<<n-it->second<<endl;
    }
    return 0;
}