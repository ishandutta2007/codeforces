#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
vector <ll> tt[1000];
set <ll> ss;
map < string, ll > mp;
string s,s1;
char cc[100][100],ckek;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n!=0)
    {
        if(n%2==1)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
ll stn,fl,v[100000],dl,mx,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1;
int main()
{

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll aa,bb;
    cin >> n >> aa >> bb;
    for(i=0;i<n;i++)
    {
       cin >> a1 >> b1;
       stn++;
       a[stn]=a1;
       b[stn]=b1;
       v[stn]=i+1;
       stn++;
       a[stn]=b1;
       b[stn]=a1;
       v[stn]=i+1;
    }
    for(i=1;i<=stn;i++)
        for(j=1;j<=stn;j++)if(v[i]!=v[j])
    {
     //   if(v[i]==1 and v[j]==3)cout << a[i] << " " << a[j] << endl << b[i] << " " << b[j] << endl;
        if(a[i]+a[j]<=aa and max(b[i],b[j])<=bb)mx=max(mx,a[i]*b[i]+a[j]*b[j]);
        if(b[i]+b[j]<=bb and max(a[i],a[j])<=aa)mx=max(mx,a[i]*b[i]+a[j]*b[j]);
    }
    cout << mx << endl;
    return 0;
}