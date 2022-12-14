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
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll l,r,c,sc,n,m,i,j,a[MAXN],a1,b1,c1,ans,x,k;
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
    cin >> n >> k;
    sc=1;
    if(k==1)vout(sc);
    sc+=(n*(n-1))/2;
    if(k==2)vout(sc);
    //sc=0;
    for(i=2;i<n;i++)sc+=(i*(i-1));
    if(k==3)vout(sc);
ll    ke=0;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            ll kl=n-j;
            ke+=(kl*(kl-1))/2*9;
        }
    }
    cout << sc+ke << endl;
    return 0;
}