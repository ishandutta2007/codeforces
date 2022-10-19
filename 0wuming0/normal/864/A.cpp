#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    while(n--)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    if(mp.size()==2)
    {
        auto it=mp.begin();
        int a=it->first,b=it->second,c,d;
        it++;
        c=it->first,d=it->second;
        if(b==d)
        {
            cout<<"YES"<<endl;
            cout<<a<<" "<<c<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}