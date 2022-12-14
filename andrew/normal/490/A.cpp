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
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
vector <ll> v[MAXN];
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k,dp[MAXN];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    i=0;
    while(n--)
    {
        i++;
        cin >> a1;
        a[a1]++;
        v[a1].p_b(i);
    }
    k=min(a[1],min(a[2],a[3]));
    cout << k << endl;
    for(i=0;i<k;i++)cout << v[1][i] << " " << v[2][i] << " " << v[3][i] << endl;

    return 0;
}