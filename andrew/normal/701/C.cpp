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
string s;
map < string, ll > mp;
string s2,s1,s3;
char cc;
ll a[MAXN];
ll bl[MAXN],c,sc,n,m,i,j,dp[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll check()
{
    ll res=1e18;
    for(ll i=0;i<52;i++)if(a[i])res=min(res,b[i]);
    return res;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("cycle.in","r",stdin);
    //freopen("cycle.out","w",stdout);
    cin >> n;
    for(i='a';i<='z';i++)s2+=char(i);
    for(i='A';i<='Z';i++)s2+=char(i);
    cin >> s;
    for(i=0;i<n;i++)
    {
        cc=s[i];
        ll h=s2.find(cc);
        a[h]=1;
    }
    ll l=0;
    ll r=0;
    ans=1e18;
    while(r<n)
    {
        ll h=s2.find(s[r]);
        b[h]++;
        while(l<=r && check()>0){
            ans=min(ans,r-l+1);
            h=s2.find(s[l]);
            b[h]--;
            l++;
        }
        r++;
    }

    reverse(s.begin(),s.end());
    for(i=0;i<52;i++)b[i]=0;
    l=r=0;
    while(r<n)
    {
        ll h=s2.find(s[r]);
        b[h]++;
        while(l<=r && check()>0){
            ans=min(ans,r-l+1);
            h=s2.find(s[l]);
            b[h]--;
            l++;
        }
        r++;
    }
    cout << ans << endl;
    return 0;
}