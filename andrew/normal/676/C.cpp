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
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
set <pll> st;
set <ll> s;
unordered_map < string , ll > mp;
vector <pll> v[MAXN];
string s2,s1,s3;
char cc;
ll q1=1,c,sc,n,m,i,j,a[MAXN],a1,b1,c1,ans,x,k;
ll d[MAXN][2];
ll check(ll de,ll l,ll r)
{
    a1=d[r][0]-d[l-1][0];
    b1=d[r][1]-d[l-1][1];
    if(de==0)return b1;
    return a1;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("path.in","r",stdin);
    //freopen("path.out","w",stdout);
    cin >> n >> k;
    cin >> s1;
    for(i=1;i<=n;i++)
    {
        if(s1[i-1]=='a')a1++;else b1++;
        d[i][0]=a1;
        d[i][1]=b1;
    }
    ll l,r;
    for(i=1;i<=n;i++)
    {
        l=i;
        r=n;
        for(j=0;j<100;j++)
        {
            if(l>r)break;
            ll c=(l+r)/2;
            c1=check(0,i,c);
            //cout << l << " " << c << " " << c1 << " " << i << endl;
            if(c1<=k)
            {
                ans=max(ans,c-i+1);
            }
            if(c1<=k)l=c+1;else r=c;
        }
    }
    for(i=1;i<=n;i++)
    {
        l=i;
        r=n;
        for(j=0;j<100;j++)
        {
            if(l>r)break;
            ll c=(l+r)/2;
            c1=check(1,i,c);
            if(c1<=k)
            {
                ans=max(ans,c-i+1);
            }
            if(c1<=k)l=c+1;else r=c;
        }
    }
    cout << ans << endl;
    return 0;
}