#include"bits/stdc++.h"
using namespace std;
#define ll long long
int x[100005];
int c[100005];
map<int,int>mp;
int main()
{
    int n,k,a;
    cin>>n>>k;
    for(int i=0;i<n;i++)scanf("%d",x+i);
    cin>>a;
    for(int i=0;i<n;i++)scanf("%d",c+i);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        map<int,int>::iterator it=mp.find(c[i]);
        if(it==mp.end())mp[c[i]]=1;
        else it->second++;
        while(k<x[i])
        {
            if(mp.size()==0)
            {
                cout<<-1<<endl;
                return 0;
            }
            it=mp.begin();
            it->second--;
            ans=ans+it->first;
            if(it->second==0)mp.erase(it);
            k+=a;
        }
    }
    cout<<ans<<endl;
    return 0;
}