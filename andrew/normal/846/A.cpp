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
ll a[maxn],b[2][maxn],c[2][maxn],a1,b1,c1,n,m,x,i,j,sc,ans,k;
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
    cin >> n;
    if(n==1)vout("1");
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        b[0][i]=b[0][i-1],b[1][i]=b[1][i-1];
        if(i>0)b[a[i]][i]++;
    }
    for(i=n;i>0;i--)
    {
        c[0][i]=c[0][i+1],c[1][i]=c[1][i+1];
        c[a[i]][i]++;
    }
    for(i=0;i<=n;i++)ans=max(ans,b[0][i]+c[1][i+1]);

    cout << ans << endl;
return 0;
}