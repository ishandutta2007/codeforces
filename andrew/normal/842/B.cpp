#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
double a[maxn],b[maxn],c,a1,b1,c1,m,x,sc,k;
ll i,j,n,ans;
template <typename T>
T sqr(T a)
{
    return a*a;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

  double r,d,dd;
  cin >> r >> d;
  dd=r-d;
  cin >> n;
  for(i=0;i<n;i++)
  {
      double x1,y1,r1;
      cin >> x1 >> y1 >> r1;
        if(sqrt(sqr(x1)+sqr(y1))-r1>=dd && sqrt(sqr(x1)+sqr(y1))+r1<=r)ans++;
  }
cout << ans << endl;
return 0;
}