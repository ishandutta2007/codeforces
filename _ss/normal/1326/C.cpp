#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=4e5+10;
const ll mod=998244353;
int n,vt[N],k;
ll val[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1,x;i<=n;i++) cin>>x,vt[x]=i;
    ll res1=0;
    for (int i=1;i<=k;i++) val[i]=vt[n-i+1],res1+=(ll)n-i+1;
    sort(val+1,val+k+1);
    ll res2=1;
    for (int i=1;i<k;i++) res2=res2*(val[i+1]-val[i])%mod;
    cout<<res1<<" "<<res2;
    return 0;
}