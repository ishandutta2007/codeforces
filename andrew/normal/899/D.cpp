#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
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
set <pll> s,s1;
const ll shl=1;
const ll MAXN=1123456;
char cc;
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
   x=2*n-1;
   ll fl=0;
   while(x)
   {
       k++;
       if(x%10!=9)fl=1;
       x/=10;
   }
   if(fl==0)vout(1);
   sc=1;
   for(i=1;i<k;i++)x=x*10+9;
   for(i=1;i<k;i++)sc*=10;
   //cout << sc << " " << x << endl;
   for(i=0;i<9;i++)
   {
       //cout << x << endl;
       if(x>2*n-1)break;
       if(x<n+2)ans+=(x-1)/2;else ans+=(2*n+1-x)/2;
       x+=sc;
   }
   cout << ans << endl;
    return 0;
}