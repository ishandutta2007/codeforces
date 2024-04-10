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
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a1;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=n;i>0;i--,k--)if(k>0)a[i]=min(a[i],a1);
    for(i=1;i<=n;i++)ans+=a[i];
    cout << ans << endl;
return 0;
}