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
pll kek;
set <pll> s;
double mx;
ll mxx,myy,p[1000000],i,n,m,k,sc,dp[1000000],x,a[100000],b[100000],a1,b1,c1,ans;
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
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=k;i++)
    {
        ans+=sc;
        sc+=a[i];
        s.insert(m_p(a[i],i));
    }
    k++;
    ans+=sc;
    while(1)
    {
        if(s.size()==0 && k>n)break;
        if(k<=n)
        {
            s.insert(m_p(a[k],k));
            sc+=a[k];
        }
        set <pll> ::iterator it=s.end();
        --it;
        kek=*it;
        s.erase(it);
        sc-=kek.fi;
        p[kek.se]=k;
        k++;
        ans+=sc;
    }
    cout << ans << endl;
    for(i=1;i<=n;i++)cout << p[i] << " ";
    cout << endl;
    return 0;
}