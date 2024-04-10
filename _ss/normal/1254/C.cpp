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
const ll maxn=1e3+10,mod=1e9+7,inf=1e18;

vector<pii> vt;
vector<int> vt1,vt2;
int n;

int main()
{
    //freopen("ss.inp","r",stdin);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin>>n;
    int t=2;
    for (int i=3,x;i<=n;i++)
    {
        cout<<2<<" "<<1<<" "<<t<<" "<<i<<"\n";
        fflush(stdout);
        cin>>x;
        if (x==-1) t=i;
    }
    ll ma=0,h;
    for (int i=2;i<=n;i++)
        if (i!=t)
        {
            cout<<1<<" "<<1<<" "<<t<<" "<<i<<"\n";
            fflush(stdout);
            ll tmp;
            cin>>tmp;
            if (tmp>ma) ma=tmp,h=i;
            vt.pb(mp(tmp,i));
        }
    sort(all(vt));
    for (pii x : vt)
    if (x.se!=h)
    {
        cout<<2<<" "<<1<<" "<<x.se<<" "<<h<<"\n";
        fflush(stdout);
        int tmp;
        cin>>tmp;
        if (tmp==1) vt1.pb(x.se);
        else vt2.pb(x.se);
    }
    cout<<"0 1 "<<t<<" ";
    for (int i=0;i<vt1.size();i++) cout<<vt1[i]<<" ";
    cout<<h<<" ";
    for (int i=vt2.size()-1;i>=0;i--) cout<<vt2[i]<<" ";
    return 0;
}