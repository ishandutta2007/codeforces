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
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < ll , ll > mp,mp1;
string s,s1;
char cc;
ll p[1000000],c,sc,n,m,i,j,a,b,a1,b1,c1,ans,x,k;
void vout(string s)
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
    cin >> a >> b;
   // cout << a << endl;
    if(b<a)vout("0");
    if(a==b)vout("1");
//    cout << fac(b)/fac(a) << endl;;
    c1=a%10+1;
    ans=1;
    a1=10;
    for(i=c1;i<=min(a1,b%10);i++)ans*=i;

    //cout << ans << endl;
    //cout << ans << endl;
    if(a/10!=b/10)vout("0");
    cout << ans%10 << endl;
    return 0;
}
/*

217
316

6 8

116
119
651 240 548 333 620 923 651 240 548 333 620 924
*/