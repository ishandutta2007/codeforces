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
char cc;
set <pll> s;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   cin >> n;
   ll mx1=-1e18,mn1=1e18;
   for(i=0;i<n;i++)
   {
       cin >> a1 >> b1;
       mn1=min(mn1,b1);
       mx1=max(mx1,a1);
   }
   cin >> n;
   ll mx2=-1e18,mn2=1e18;
   for(i=0;i<n;i++)
   {
       cin >> a1 >> b1;
       mn2=min(mn2,b1);
       mx2=max(mx2,a1);
   }
   cout << max(0ll,max(mx2-mn1,mx1-mn2));
    return 0;
}