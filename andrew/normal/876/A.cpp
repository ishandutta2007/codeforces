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
ll a1,b1,c1,stn,x,k,ans,n,m,l,r,b[1000000],c[1000000],sc,i,mn=1e18,mx=-1e18;
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("bow.in","r",stdin);
    //freopen("bow.out","w",stdout);
    cin >> n;
    cin >> a1 >> b1 >> c1;
    if(n==1)vout(0);
    if(n==2)vout(min(a1,b1));
    n--;
   // cout << a1 << " " << b1 << " " << c1 << endl;
    cout << min(a1*n,min(b1*n,min(a1,b1)+c1*(n-1))) << endl;
   return 0;
}