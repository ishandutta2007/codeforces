#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pll pair <ll,ll>
#define m_p make_pair
#define p_b push_back
using namespace std;
vector <ll> tt[10000];
void vout(ll x)
{
    cout << x << endl;
    exit(0);
}
multiset <ll> s;
ll a[1000000];
ll a1,b1,c1,stn,x,k,ans,n,m,l,r,b[1000000],j,c[1000000],sc,i,mn=1e18,mx=-1e18;
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("bow.in","r",stdin);
    //freopen("bow.out","w",stdout);
    cin >> n;
    m=min(100ll,n);
    for(i=1;i<=m;i++)
    {
        x=n-i;
        sc=0;
        a1=x;
        while(a1)
        {
            sc+=a1%10;
            a1/=10;
        }
        if(sc==i)
        {
            k++;
            a[k]=x;
        }
    }
    cout << k << endl;
    sort(a+1,a+k+1);
    for(i=1;i<=k;i++)cout << a[i] << endl;
   return 0;
}