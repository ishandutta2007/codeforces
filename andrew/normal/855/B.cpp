#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
template <typename T>
T sqr(T x)
{
    return x*x;
}
const ll shl=1;
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s1;
set <pll> s[1000000];
char cc;
ll dp[1000000],sc,n,m,i,j,a[1000000],b[1000000],c[1000000],a1,b1,c1,ans,x,k,mxx,mn,p,r,q,mx;
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> p >> q >> r;
    mxx=-4*1e18;
    //cout << mxx << endl;
    mx=-4*1e18;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=n;i>0;i--)
    {
        mxx=max(mxx,a[i]*r);
        mx=max(mx,a[i]*q+mxx);
        dp[i]=mx;
    }
    ans=-4*1e18;
    for(i=1;i<=n;i++)ans=max(ans,dp[i]+a[i]*p);
    cout << ans << endl;
    return 0;
}