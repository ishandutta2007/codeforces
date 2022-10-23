#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e2+10,inf=1e9,V=1e6;
ll n,a[N],k;

ll check(ll d)
{
    ll cost=0,st=0;
    for (int i=1;i<=n;i++)
    {
        ll t=(a[i]-1)/d+1;
        cost+=t*d-a[i];
        st+=t;
    }
    if (cost>k) return -1;
    return d+(k-cost)/st;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll res=1;
    for (int i=1;i<=V;i++) res=max(res,check(i));
    for (int i=1;i<=n;i++)
        for (int t=1;t<=inf/V;t++) res=max(res,check((a[i]-1)/t+1));
    cout<<res;
    return 0;
}