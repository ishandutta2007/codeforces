#include <bits/stdc++.h>
using namespace std;
typedef long double  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const int maxn=1000000;
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,sc,ans,k;
int i,j;
map <ll,ll> mp;
template <typename T>
T sqr(T a)
{
    return a*a;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)sc+=a[i];
    for(i=0;i<n;i++)mp[a[i]]++;

    for(i=0;i<n;i++)
    {
        ll kl=n-i;
        ll sc1=sc;
        sc1-=a[i]*mp[a[i]];
        kl-=mp[a[i]];
        a[i]--;
        sc1-=a[i]*mp[a[i]];
        kl-=mp[a[i]];
        a[i]+=2;
        sc1-=a[i]*mp[a[i]];
        kl-=mp[a[i]];
        a[i]--;
        ans+=sc1-kl*a[i];
        sc-=a[i];
        mp[a[i]]--;
    }
    cout << fixed << setprecision(0) << ans << endl;
return 0;
}