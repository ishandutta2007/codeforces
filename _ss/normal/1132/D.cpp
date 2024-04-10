#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+1;
ll n,k,a[maxn],b[maxn],c[maxn],so[maxn];

void read()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) /*scanf("%d",&a[i]);*/
        cin>>a[i];
    for (int i=1;i<=n;i++) //scanf("%d",&b[i]);
        cin>>b[i];
    //for (int i=1;i<=n;i++) a[i]+=b[i];
    k--;
}
bool f(ll x)
{
    ll t,d=0;
    for (int i=1;i<=n;i++) c[i]=a[i];
    for (int i=1;i<=k;i++) so[i]=0;
    for (int i=1;i<=n;i++)
    {
        ll h=0;
        while (h<k)
        {
            t=c[i]/b[i]+1;
            h+=t-1;
            if (h>=k) break;
            c[i]=(c[i]%b[i])+x;
            d++;
            so[h+1]++;
            if (d>k) return false;
        }
    }
    vector<ll> st;
    st.pb(0);
    for (int i=1;i<=k;i++)
        for (int j=1;j<=so[i];j++) st.pb(i);
    for (int i=1;i<st.size();i++)
        if (st[i]<i) return false;
    return true;
}

ll bs()
{
    ll l=0,r=1e13,mid,tp=-1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (f(mid)) r=mid-1,tp=mid; else l=mid+1;
    }
    return tp;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    cout<<bs();
    return 0;
}