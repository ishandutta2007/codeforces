#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=3e5+10;
ll n,x1,x2;
pii c[N];

bool cmp(pii t1,pii t2) {return t1>t2;}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x1>>x2;
    for (int i=1;i<=n;i++) cin>>c[i].fi,c[i].se=i;
    sort(c+1,c+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        ll sl2=(x2-1)/c[i].fi+1;
        if (i-sl2<1) continue;
        ll sl1=(x1-1)/c[i-sl2].fi+1;
        if (sl1+sl2<=i)
        {
            cout<<"Yes\n"<<i-sl2<<" "<<sl2<<"\n";
            for (int j=1;j<=i-sl2;j++) cout<<c[j].se<<" ";
            cout<<"\n";
            for (int j=i-sl2+1;j<=i;j++) cout<<c[j].se<<" ";
            return 0;
        }
    }
    swap(x1,x2);
    for (int i=1;i<=n;i++)
    {
        ll sl2=(x2-1)/c[i].fi+1;
        if (i-sl2<1) continue;
        ll sl1=(x1-1)/c[i-sl2].fi+1;
        if (sl1+sl2<=i)
        {
            cout<<"Yes\n"<<sl2<<" "<<i-sl2<<"\n";
            for (int j=i-sl2+1;j<=i;j++) cout<<c[j].se<<" ";
            cout<<"\n";
            for (int j=1;j<=i-sl2;j++) cout<<c[j].se<<" ";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}