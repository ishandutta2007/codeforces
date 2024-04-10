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
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;
int a[maxn],n,s=0;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    if (s==1)
    {
        cout<<-1;
        return 0;
    }
    ll res=inf;
    for (int i=2;i<=s;i++)
        if (s%i==0)
        {
            ll kq=0;
            vector<ll> tmp;
            for (int j=1;j<=n;j++)
                if (a[j])
                {
                    tmp.pb(j);
                    if (tmp.size()==i)
                    {
                        ll tt=tmp[(i-1)/2];
                        for (ll u : tmp) kq+=abs(tt-u);
                        tmp.clear();
                    }
                }
            res=min(res,kq);
        }
    cout<<res;
    return 0;
}