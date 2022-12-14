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
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
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
string s,s1[100];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n;
   if(n==2)
   {
       cout << 3 << endl << "2 1 2" << endl;
       return 0;
   }
   if(n==3)
   {
       cout << 4 << endl << "2 1 3 2" << endl;
       return 0;
   }
  else
   {
       cout << n+n/2 << endl;
       for(i=1;i<=n;i++)if(i%2==0)cout << i << " ";
       for(i=1;i<=n;i++)if(i%2)cout << i << " ";
        for(i=1;i<=n;i++)if(i%2==0)cout << i << " ";
   }
return 0;
}