#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;
ll cnt[100],fact[21];

ll solve(ll x)
{
    ll d=2;
    for (int i=0;i<=25;i++) cnt[i]=0;
    while (x)
    {
        cnt[x%d]++;
        x/=d;
        d++;
    }
    ll tmp=1;
    for (int i=0;i<=25;i++) tmp*=fact[cnt[i]];
    d--;
    ll res=1;
    for (ll i=2;i<=d;i++)
    {
        cnt[i-1]+=cnt[i-2];
        res*=cnt[i-1]-i+2;
    }
    ll res2=1;
    if (cnt[0])
    {
        for (ll i=2;i<d;i++)
            res2*=cnt[i-1]-i+1;
        res2=res2/(tmp/fact[cnt[0]]*fact[(cnt[0]-1)]);
    }
    else res2=0;
    return res/tmp-res2-1;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fact[0]=1;
    for (ll i=1;i<=20;i++) fact[i]=fact[i-1]*i;
    ll q,x;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>x;
        cout<<solve(x)<<"\n";
    }
    return 0;
}