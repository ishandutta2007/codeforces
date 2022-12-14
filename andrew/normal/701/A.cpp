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
set <ll> s;
map < string, ll > mp;
string s2,s1,s3;
char cc;
pll a[MAXN];
ll bl[MAXN],c,sc,n,m,i,j,dp[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("cycle.in","r",stdin);
    //freopen("cycle.out","w",stdout);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i].fi;
        a[i].se=i+1;
    }
    sort(a,a+n);
    ll l=0,r=n-1;
    while(l<r){
            cout << a[l].se << " " << a[r].se << endl;
    l++;
    r--;
    }
    return 0;
}