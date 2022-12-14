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
ll a[MAXN],c,sc,n,m,i,j,b[MAXN],a1,b1,c1,ans,x,k;
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
   cin >> a1 >> b1 >> c1;
   if(a1==b1)vout("YES");
   if(c1==0)vout("NO");
   if(a1<b1 && c1<0)vout("NO");
   if(a1>b1 && c1>0)vout("NO");
   if((b1-a1)%c1==0)vout("YES");
   vout("NO");
    return 0;
}