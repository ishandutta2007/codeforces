#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e18;
struct ds
{
    ll s,a,b;
};
ll n,sl;
vector<ds> t1,t2;

bool cmp1(ds ob1,ds ob2) {return (ob1.b-ob1.a)>(ob2.b-ob2.a);}
bool cmp2(ds ob1,ds ob2) {return (ob1.b-ob1.a)<(ob2.b-ob2.a);}
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>sl;
    ll s,a,b,ans=0,tsl1=0,tsl2=0;
    for (int i=1;i<=n;i++)
    {
        cin>>s>>a>>b;
        if (a>b)
        {
            ans+=a*s;
            t1.pb({s,a,b});
            tsl1+=s;
        }
        else
        {
            ans+=b*s;
            t2.pb({s,a,b});
            tsl2+=s;
        }
    }
    tsl1%=sl;
    tsl2%=sl;
    if (tsl1+tsl2>sl)
    {
        cout<<ans;
        return 0;
    }
    sort(t1.begin(),t1.end(),cmp1);
    sort(t2.begin(),t2.end(),cmp2);
    ll k1=0,k2=0;
    for (int i=0;i<t1.size() && tsl1;i++)
        if (t1[i].s>tsl1)
        {
            k1+=(t1[i].b-t1[i].a)*tsl1;
            tsl1=0;
        }
        else
        {
            k1+=(t1[i].b-t1[i].a)*t1[i].s;
            tsl1-=t1[i].s;
        }
    for (int i=0;i<t2.size() && tsl2;i++)
        if (t2[i].s>tsl2)
        {
            k2+=(t2[i].a-t2[i].b)*tsl2;
            tsl2=0;
        }
        else
        {
            k2+=(t2[i].a-t2[i].b)*t2[i].s;
            tsl2-=t2[i].s;
        }
    cout<<ans+max(k1,k2);
    return 0;
}