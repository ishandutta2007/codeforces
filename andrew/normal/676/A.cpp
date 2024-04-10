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
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
    {
        swap(a[i],a[j]);
        for(ll i1=1;i1<=n;i1++)
        {
            if(a[i1]==1)a1=i1;
            if(a[i1]==n)b1=i1;
        }
        ans=max(ans,abs(a1-b1));
        swap(a[i],a[j]);
    }
    cout << ans << endl;
    return 0;
}