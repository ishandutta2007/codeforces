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
vector <ll> tt[1000];
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   cin >> n;
   for(i=1;i<=n;i++)cin >> a[i];
   for(i=1;i<=n;i++)b[i]=a[i];
   sort(b+1,b+n+1);
   for(i=1;i<=n;i++)
   {
       for(j=i;j<=n;j++)if(a[j]==b[i])
       {
           k=j;
           while(k>i)
           {
               cout << k-1 << " " << k << endl;
               swap(a[k],a[k-1]);
               k--;
           }
           break;
       }
   }
 //  for(i=1;i<=n;i++)cout << a[i] << " ";
    return 0;
}