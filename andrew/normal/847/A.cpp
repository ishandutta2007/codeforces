#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
vector <ll> tt[1000];
char cc;
ll p[1000000],i,j,n,m,k,sc,s,dp[1000000],x,a[100000],b[100000],a1,b1,c1,l[1000000],r[1000000],ans,mx=-1e18,v[1000000];
void fout(string s)
{
    cout << s << endl;
    fflush(stdout);
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
ll gcd(ll a,ll b)
{
    while(a>0 && b>0)a>b?a%=b:b%=a;
    return a+b;
}
void dfs(ll x)
{
    if(v[x])return;
    v[x]=ans;
    ll i;
    for(i=1;i<=n;i++)if(x==a[i])dfs(i);
    return;
}
int main() {
    ll l1,r1;
    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    r[0]=-1;
    l[0]=-1;
    for(i=1;i<=n;i++)cin >> a[i] >> b[i];
    for(i=1;i<=n;i++)if(!v[x] && a[i]==0)
    {
        ans++;
        dfs(i);
    }
    for(i=1;i<=n;i++)l[i]=a[i],r[i]=b[i];
    ll i1;
    for(i=1;i<ans;i++)
    {
        for(i1=1;i1<=n;i1++)if(i==v[i1] && r[i1]==0)
        {
            for(j=1;j<=n;j++)if(i+1==v[j] && l[j]==0)
            {
                l[j]=i1;
                r[i1]=j;
                break;
            }
            break;
        }
    }
    for(i=1;i<=n;i++)cout << l[i] << " " << r[i] << endl;
    return 0;
}