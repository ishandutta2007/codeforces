#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
ll n,a[maxn],b[maxn],x;
int main()
{
    cin>>n;
    for (ll i=1;i<=n*2;i++)
    {
        cin>>x;
        if (a[x]==0) a[x]=i; else b[x]=i;
    }
    for (ll i=2;i<=n-1;i++)
        if ((abs(a[i]-a[i-1])+abs(a[i+1]-a[i])+abs(b[i]-b[i-1])+abs(b[i+1]-b[i]))>(abs(b[i]-a[i-1])+abs(a[i+1]-b[i])+abs(a[i]-b[i-1])+abs(b[i+1]-a[i]))) swap(a[i],b[i]);
    if (abs(a[n]-a[n-1])+abs(b[n]-b[n-1])>abs(b[n]-a[n-1])+abs(a[n]-b[n-1])) swap(a[n],b[n]);
    ll kq=abs(a[1]-1)+abs(b[1]-1);
    for (int i=2;i<=n;i++) kq=kq+abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
    cout<<kq;
    //for (int i=1;i<=n;i++) cout<<a[i]<<" "<<b[i]<<endl;
    return 0;
}