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
vector <string> sans;
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
template <typename T>
T sqr(T a)
{
    return a*a;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n;
   for(i=0;i<n;i++)cin >> a[i];
   sort(a,a+n);
   for(i=n-1;i>=0;i--)if(!b[i])
   {
        ans++;
        b[i]=1;
        k=a[i];
        for(j=i;j>=0;j--)if(a[j]<k && !b[j]){b[j]=1;k=a[j];}
   }
   cout << ans << endl;
return 0;
}