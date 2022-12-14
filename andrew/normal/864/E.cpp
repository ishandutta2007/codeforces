#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
pair <pll,pll> a[maxn];
vector <ll> v[100000];
ll t,mx,d,dp[100000],f[100000],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
template <typename T>
T sqr(T a)
{
    return a*a;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
string s1;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i].fi.se >> a[i].fi.fi >> a[i].se.fi;
    for(i=0;i<n;i++)a[i].se.se=i;
    sort(a,a+n);
    //dp[]=0;
    f[1]=1;
    for(i=0;i<n;i++)
    {
        t=a[i].fi.se;
        d=a[i].fi.fi;
        x=a[i].se.fi;
        ll nn=a[i].se.se+1;
        for(j=d-t;j>=0;j--)if(f[j] && dp[j]+x>dp[j+t])
        {
            dp[j+t]=dp[j]+x;
            v[j+t]=v[j];
            f[j+t]=1;
            v[j+t].p_b(nn);
        }
    }
    mx=-1e18;
    for(i=0;i<=10000;i++)mx=max(mx,dp[i]);
    for(i=0;i<=10000;i++)if(mx==dp[i])
    {
        cout << dp[i] << endl;
        cout << v[i].size() << endl;
        for(j=0;j<v[i].size();j++)cout << v[i][j] << " ";
        cout << endl;
        return 0;
    }
}