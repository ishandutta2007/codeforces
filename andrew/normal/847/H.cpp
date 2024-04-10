#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
ll c[1000000],i,n,x,a[1000000],b[1000000],c1,sc[1000000],sc1,ans=1e18;
int main() {
    ll l1,r1;
    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)b[i]=c[i]=a[i];
    sc[1]=0;
    for(i=2;i<=n;i++)
    {
        sc[i]=sc[i-1];
        x=max(b[i-1],b[i]-1);
        b[i]=x+1;
        sc[i]+=(x+1)-a[i];
    }
    ans=sc[n];
    for(i=n-1;i>0;i--)
    {
        x=max(c[i+1],c[i]-1);
        c[i]=x+1;
        sc1+=(x+1)-a[i];
        c1=sc[i-1]+sc1;
        //cout << c1 << " ";
        if(b[i]>c[i])c1+=b[i]-c[i];
        //cout << b[i] << " " << c[i] << endl;
        ans=min(ans,c1);
    }
    cout << ans << endl;
    return 0;
}