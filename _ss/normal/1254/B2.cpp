#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e6+10,mod=1e9+7,inf=2e18;
ll a[maxn],n,s=0;
vector<ll> can;
int main()
{
    //freopen("ss.inp","r",stdin);
    scanf("%I64d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]),s+=a[i];
    if (s==1)
    {
        cout<<-1;
        return 0;
    }
    ll tmp=s;
    for (ll i=2;i*i<=tmp;i++)
        if (tmp%i==0)
        {
            can.pb(i);
            while (tmp%i==0) tmp/=i;
        }
    if (tmp>1) can.pb(tmp);
    ll res=inf;
    for (ll k : can)
    {
        ll kq=0,sl=0;
        vector<pii> vt;
        for (int i=1;i<=n;i++)
            if (a[i])
            {
                if (sl+a[i]%k<k)
                {
                    vt.pb(mp(a[i]%k,i));
                    sl+=a[i]%k;
                }
                else
                {
                    vt.pb(mp(k-sl,i));
                    ll pp=a[i]%k-(k-sl),sl2=0,tt=0;
                    for (int j=0;j<vt.size();j++)
                    {
                        sl2+=vt[j].fi;
                        if (sl2>=(k+1)/2)
                        {
                            tt=vt[j].se;
                            break;
                        }
                    }
                    for (int j=0;j<vt.size();j++) kq+=abs(vt[j].se-tt)*vt[j].fi;
                    vt.clear();
                    if (pp>0) vt.pb(mp(pp,i));
                    sl=pp;
                }
            }
        res=min(res,kq);
    }
    printf("%I64d",res);
    return 0;
}