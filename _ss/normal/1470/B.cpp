#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10,V=1e6;
int lp[V+10];

void sieve()
{
    for (int i=2;i<=V;i++)
        if (!lp[i])
            for (int j=i;j<=V;j+=i)
                if (!lp[j]) lp[j]=i;
}

int cal(int x)
{
    int res=1;
    while (x>1)
    {
        int v=lp[x],d=0;
        while (lp[x]==v)
        {
            x/=v;
            d^=1;
        }
        if (d) res*=v;
    }
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        map<int,int> cnt;
        for (int i=1,x;i<=n;i++) cin>>x,x=cal(x),cnt[x]++;
        int res0=0,res1=0;
        for (pii p : cnt)
        {
            res0=max(res0,p.se);
            if (p.fi==1 || p.se%2==0) res1+=p.se;
        }
        res1=max(res1,res0);
        int q;
        cin>>q;
        for (int i=1;i<=q;i++)
        {
            ll x;
            cin>>x;
            if (x) cout<<res1<<"\n";
            else cout<<res0<<"\n";
        }
    }
    return 0;
}