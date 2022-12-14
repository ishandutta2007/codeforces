#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
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
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
vector <ll> v[MAXN];
vector <ll> va;
set <pll> st;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k,dp[5*MAXN];
ll f[5*MAXN],fk[5*MAXN],bl[5*MAXN];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    m=1ll<<n;
    cin >> k;
    if(n*(n-1)/2==k)vout(0);
    while(k--)
    {
        cin >> a1 >> b1;
        a1--;b1--;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
    }
    for(i=0;i<n;i++)
    {
        ll s=(1ll<<i);
        for(j=0;j<v[i].size();++j)s|=1ll<<v[i][j];
        a[i]=s;
    }
    for(i=1;i<m;i++)dp[i]=1e18;
    f[0]=-1;
    bl[0]=1;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)if(dp[int(i|a[j])]>dp[i]+1 && bl[i])
    {
        ll ke=(1ll<<j)&i;
        if(ke==0 && i!=0)continue;
        x=i|a[j];
        dp[x]=dp[i]+1;
        bl[x]=1;
        f[x]=j;
        fk[x]=i;
    }
    cout << dp[m-1] << endl;
    ll fe=m-1;
    while(f[fe]!=-1)
    {
        va.p_b(f[fe]);
        fe=fk[fe];
    }
    reverse(va.begin(),va.end());
    for(i=0;i<va.size();++i)cout << va[i]+1 << " ";
    cout << endl;
    return 0;
}