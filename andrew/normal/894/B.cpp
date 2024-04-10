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
const ll MAXN=1123456;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll ce,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
ll binpow (ll a, ll n)
{
    ll res=1;
    while (n)
    {
        if (n&1) res*=a%ce;
        res%=ce;
        a*=a;
        a%=ce;
        n /= 2;
    }
    return res;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m >> k;
    if(n%2+m%2==1 && k==-1)vout(0);
    ans=1;
    ce=1e9+7;
    n=(n-1);
    m=(m-1);
    ans=binpow(2ll,n)%ce;
    ans=binpow(ans,m)%ce;
    cout << ans << endl;
    return 0;
}