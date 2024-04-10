#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,k,a[100000],lo=INT_MAX;
ll ans=0;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i],lo=min(lo,a[i]);
    for(int i=0;i<n;i++){if((a[i]-lo)%k)return cout<<-1,0;ans+=(a[i]-lo)/k;}
    cout<<ans;
}