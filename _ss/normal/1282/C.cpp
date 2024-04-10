#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=4e5+10,mod=1e9+7,inf=1e18;
ll n,T,a,b;
pii tp[N];

void read()
{
    cin>>n>>T>>a>>b;
    for (int i=1;i<=n;i++) cin>>tp[i].se;
    for (int i=1;i<=n;i++) cin>>tp[i].fi;
}

void process()
{
    sort(tp+1,tp+n+1);
    ll sl0=0,sl1=0;
    for (int i=1;i<=n;i++)
        if (tp[i].se) sl1++;
        else sl0++;
    if (a*sl0+b*sl1<=T)
    {
        cout<<n<<"\n";
        return;
    }
    ll res=0,tim=0;
    for (int i=1;i<=n;i++)
    {
        ll can=i-1;
        ll lef=tp[i].fi-1-tim;
        if (lef>=0)
        {
            if (lef>=sl0*a) can+=sl0,lef-=sl0*a;
            else can+=lef/a,lef=0;
            can+=lef/b;
            res=max(res,can);
        }
        if (tp[i].se) sl1--,tim+=b;
        else sl0--,tim+=a;
    }
    cout<<res<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}