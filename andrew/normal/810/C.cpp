#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll a[300001],i,j,k,l,sc,ans,con=1000000007,st[300001];
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    st[0]=1;
    for(i=1;i<300001;i++)st[i]=(st[i-1]*2)%con;
    sort(a,a+n);
    ll res=0;
    ll x=1;
    for(i=0;i<n;i++)res+=(a[i]*st[i]),res%=con;
    for(i=0;i<n;i++)
    {
        res-=a[i];
        res=(res+con)%con;
        if(res%2==0)res/=2; else res=(res+con)/2;
        res%=con;
        ans+=res;
        ans-=a[i]*(st[n-i-1]-1);
        ans=(ans+con)%con;
    }
    cout << ans << endl;

    return 0;
}