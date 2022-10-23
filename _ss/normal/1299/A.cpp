#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,inf=(1<<30)-1;
int n,a[N],b[N],st[N],en[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],b[i]=(a[i]^inf);
    b[0]=b[n+1]=st[0]=en[n+1]=inf;
    for (int i=1;i<=n;i++) st[i]=(st[i-1] & b[i]);
    for (int i=n;i;i--) en[i]=(en[i+1] & b[i]);
    int val=0,t=1;
    for (int i=1;i<=n;i++)
        if ((st[i-1] & en[i+1] & a[i])>val)
        {
            val=(st[i-1] & en[i+1] & a[i]);
            t=i;
        }
    cout<<a[t]<<" ";
    for (int i=1;i<=n;i++)
        if (i!=t) cout<<a[i]<<" ";
    return 0;
}