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
ll r,mn=1e18,mxj,stn,sc,n,m,i,j,a[MAXN],b[MAXN],c[10],a1,b1,c1,s1,s2,ans,x,k;
ll q1,q2,q[MAXN];
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
void add(ll x)
{
    if(x<1 or b[x])return;
    b[x]=r;
    q[q1]=x;
    q1++;
    if(q1==MAXN)q1=0;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   cin >> n;
 for(i=1;i<=n;i++)cin >> a[i];
 for(i=n;i>=1;i--)if(!(b[i]))
 {
     r++;
     q1=q2=0;
     add(i);
     while(q1!=q2)
     {
         ll x=q[q2];
         x=a[x];
         add(x);
        q2++;
        if(q2==MAXN)q2=0;
     }
 }
 cout << r << endl;
    return 0;
}