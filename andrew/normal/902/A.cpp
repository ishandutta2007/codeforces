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
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
set <ll> s;
vector <ll> v[MAXN];
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
void dfs(ll x)
{
    if(b[x])return;
    b[x]=1;
    ll i,nn=v[x].size();
    for(i=0;i<nn;i++)dfs(v[x][i]);
    return;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);

    cin >> n >> m;
    while(n--)
    {
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        for(i=a1+1;i<=b1;i++)v[a1].p_b(i);
    }
    dfs(0ll);
    if(b[m])vout("YES");
    vout("NO");
    return 0;
}