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
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
vector <pll> v[MAXN];
set <pll> st;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll dp[100][5];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   cin >> n;
   dp[1][1]=1;
   dp[1][2]=1;
   for(i=2;i<=n;i++)
   {
        for(j=1;j<3;j++)dp[i][j]=dp[i-1][1]+dp[i-1][2];
    }
   for(i=1;i<=n;i++)for(j=1;j<3;j++)ans+=dp[i][j];
    cout << ans << endl;
    return 0;
}