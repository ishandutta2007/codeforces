#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define INF ((ll)1e9)

ll n;
map <ll,ll> mp;


int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        mp[a]++;
    }
    if(n%2==1)return cout<<"NO",0;
    ll blocks,last;
    for(map <ll,ll>::iterator it=mp.begin();it!=mp.end();it++)
    {
        if(it==mp.begin())
        {
            blocks=it->second;
            last=it->first;
            continue;
        }
        if(!blocks || it->first!=last+1 || it->second<blocks)return cout<<"NO",0;
        if(it->second==blocks)blocks=0;
        else if(it->second>=blocks*2)blocks+=it->second-blocks*2;
        else blocks=it->second-blocks;
        last=it->first;
    }
    cout<<((blocks)?"NO":"YES");
    return 0;
}