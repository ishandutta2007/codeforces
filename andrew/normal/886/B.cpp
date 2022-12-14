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
const ll MAXN=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s;
char cc;
ll mn=1e18,mxj,stn,sc,n,m,i,j,a[MAXN],b[MAXN],c[10],a1,b1,c1,s1,s2,ans,x,k;
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
   for(i=1;i<=n;i++)
   {
       cin >> x;
       b[x]=i;
   }
    for(i=0;i<=200000;i++)if(b[i]!=0 && b[i]<mn)
    {
        mn=b[i];
        mxj=i;
    }
    cout << mxj << endl;
    return 0;
}