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
vector <ll> v[MAXN];
set <pll> st;
set <ll> s,s1;
map < string, ll > mp;
string s2,s3;
char cc;
ll a[MAXN];
ll bl[MAXN],c,sc,n,m,i,j,dp[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("cycle.in","r",stdin);
    //freopen("cycle.out","w",stdout);
    cin >> n >> m;
    while(m--)
    {
        cin >> a1 >> b1;
        s.insert(a1);
        s1.insert(b1);
        a1=s.size();
        b1=s1.size();
        ans=n*(a1+b1);
        ans-=(a1*b1);
        cout << n*n-ans << " " ;
    }
    cout << endl;
    return 0;
}