#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e7;
int lp[N+10],sl[N+10];
ll cnt[N+10];

void sieve()
{
    for (int i=2;i<=N;i++)
        if (!lp[i])
            for (int j=i;j<=N;j+=i)
                if (!lp[j]) lp[j]=i;
}

void pt(int x,int v)
{
    while (lp[x])
    {
        cnt[lp[x]]+=v;
        x/=lp[x];
    }
}

ll cal(ll val,int x)
{
    ll res=0,t=x;
    while (t<=val)
    {
        res+=val/t;
        t*=x;
    }
    return res;
}

ll mini(int x)
{
    ll l=2,r=1e13,ans;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (cal(mid,x)>=cnt[x]) ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    sieve();
    for (int i=1,x;i<=n;i++) cin>>x,sl[x+1]--;
    sl[1]=n;
    for (int i=2;i<=N;i++) sl[i]+=sl[i-1],pt(i,sl[i]);
    ll res=1;
    for (int i=2;i<=N;i++)
        if (cnt[i]) res=max(res,mini(i));
    cout<<res;
    return 0;
}