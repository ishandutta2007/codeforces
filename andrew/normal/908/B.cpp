#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
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
vector <pll> v[MAXN];
set <pll> st;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,b[MAXN],a1,b1,c1,ans,x,k,xk,xn,yk,yn;
ll a[100][100];
pll xd[5];
ll check(ll i1,ll j1,ll i2,ll  j2)
{
    ll d[5];
    d[0]=i1;
    d[1]=j1;
    d[2]=i2;
    d[3]=j2;
    ll ye=yn,xe=xn;
    for(ll i=0;i<s1.size();i++)
    {
        ll k=d[b[i]];
        ye+=xd[k].fi;
        xe+=xd[k].se;
        if(xe<1 or xe>m or ye<1 or ye>n or a[ye][xe])return 0;
        if(xe==xk && ye==yk)return 1;
    }
    return 0;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    xd[0]=m_p(0,1);
    xd[1]=m_p(0,-1);
    xd[2]=m_p(1,0);
    xd[3]=m_p(-1,0);
    ll x1,y1,x2,y2;
    cin >> n >> m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        cin >> cc;
        if(cc=='#')a[i][j]=1;
        if(cc=='S')
        {
            yn=i;
            xn=j;
        }
        if(cc=='E')
        {
            yk=i;
            xk=j;
        }
    }

    cin >> s1;
    for(i=0;i<s1.size();i++)
    {
        cc=s1[i];
        b[i]=cc-'0';
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        for(ll i1=0;i1<4;i1++)
        for(ll j1=0;j1<4;j1++)if(i!=j && i!=i1 && i!=j1 && j!=i1 && j!=j1 && i1!=j1)ans+=check(i,j,i1,j1);
    cout << ans << endl;
    return 0;
}