#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (101*1000)

ll n,x,a[N];
multiset <ll> s;

int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++)cin>>a[i],s.insert(a[i]);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll i;
    for(i=n-1;i>=0;i--)
    {
        ll p=x-a[i];
        set <ll>::iterator it=s.lower_bound(p);
        if(it==s.end())break;
        s.erase(it);
    }
    cout<<"1 "<<n-1-i;
    return 0;
}