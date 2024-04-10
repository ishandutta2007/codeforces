#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e6+1,msiz=2,mod=1e9+7,inf=1e18;
ll n,k,l[maxn],r[maxn],a[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    a[0]=a[n+1]=inf;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    stack<ll> st;
    st.push(0);
    for (int i=1;i<=n;i++)
    {
        while (a[i]>a[st.top()]) st.pop();
        l[i]=st.top()+1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    st.push(n+1);
    for (int i=n;i;i--)
    {
        while (a[i]>=a[st.top()]) st.pop();
        r[i]=st.top()-1;
        st.push(i);
    }
    for (int i=1;i<=n;i++)
        if (i-l[i]<=r[i]-i)
        {
            for (int j=l[i];j<=i;j++) ans=(ans+((r[i]-j)/(k-1)-(i>j)*(i-j-1)/(k-1))*a[i])%mod;
        }
        else
        {
            for (int j=i;j<=r[i];j++) ans=(ans+((j-l[i])/(k-1)-(j>i)*(j-i-1)/(k-1))*a[i])%mod;
        }
    //for (int i=1;i<=n;i++) ans=(ans+mod-a[i])%mod;
    //for (int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<endl;
    cout<<ans;
    return 0;
}