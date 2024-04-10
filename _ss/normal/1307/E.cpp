#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=5e3+10,mod=1e9+7;
int n,m,a[N],cnt[N],sl[N],ps[N][N];
vector<int> cow[N];

void read()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        sl[i]=cnt[a[i]];
    }
    for (int i=1,f,h;i<=m;i++) cin>>f>>h,cow[f].pb(h);
}

pii cal(int mid)
{
    pii res;
    int flag=0,d=0;
    if (mid==0) flag=1;
    for (int h : cow[a[mid]])
        if (h==sl[mid]) flag=1;
        else if (h<=cnt[a[mid]]-sl[mid]) d++;
    if (!flag) return mp(0,0);
    if (d) res=mp(2,d);
    else res=mp(1,1);
    if (mid==0) res=mp(0,1);
    for (int i=1;i<=n;i++)
        if (cnt[i] && i!=a[mid])
        {
            d=0;
            ll slp=0,d2=0;
            for (int h : cow[i])
            {
                if (h<=cnt[i]-ps[mid][i]) slp+=d,d2++;
                if (h<=ps[mid][i]) d++,d2++;
            }
            d=0;
            for (int h : cow[i])
            {
                if (h<=ps[mid][i]) slp+=d;
                if (h<=cnt[i]-ps[mid][i]) d++;
            }
            if (slp==0)
            {
                if (d2) res=mp(res.fi+1,res.se*d2%mod);
            }
            else res=mp(res.fi+2,slp%mod*res.se%mod);
        }
    return res;
}

void process()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) ps[i][j]=ps[i-1][j];
        ps[i][a[i]]++;
    }
    pii res=mp(0,1);
    for (int mid=0;mid<=n;mid++)
    {
        pii tmp=cal(mid);
        if (tmp.fi>res.fi) res=tmp;
        else if (tmp.fi==res.fi) res.se=(res.se+tmp.se)%mod;
    }
    if (res.fi==0) res.se=1;
    cout<<res.fi<<" "<<res.se;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}