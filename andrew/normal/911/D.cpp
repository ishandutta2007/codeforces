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
ll fl[MAXN],dp[MAXN],c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
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
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)if(a[j]<a[i])ans++;
    cin >> m;
    while(m--)
    {
        ll l,r;
        cin >> l >> r;
        ll t=(r-l+1);
        ans+=(t/2)%2;
        if(ans%2==1)cout << "odd";else cout << "even";
        cout << endl;
    }
    return 0;
}