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
const ll MAXN=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll c,sc,n,m,i,j,a[1000][1000],b[MAXN],a1,b1,c1,ans,x,k,dd[MAXN],v[MAXN];
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
void dfs(ll ij,ll x)
{
    v[ij]=1;
    ll i;
    k*=10;
    k+=x;
    dd[k]=1;
    ll j;
    for(i=1;i<=n;i++)if(!v[i])
    {
        for(j=1;j<7;j++)dfs(i,a[i][j]);
    }
    v[ij]=0;
    k/=10;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
        for(j=1;j<7;j++)cin >> a[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<7;j++)dfs(i,a[i][j]);

    for(i=1;i<=100000;i++)if(!dd[i])
    {
        cout << i-1 << endl;
        break;
    }
    return 0;
}