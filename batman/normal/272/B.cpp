#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e9)
#define N (301*1000)

ll n,a[N],ans;
map <ll,ll> num;

ll calc(ll x)
{
    ll res=0;
    while(x)
        res+=x%2,x/=2;
    return res; 
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        num[calc(a[i])]++;
    }
    for(map <ll,ll>::iterator it=num.begin();it!=num.end();it++)
        ans+=it->second*(it->second-1)/2;
    cout<<ans;      
    
    return 0;
}