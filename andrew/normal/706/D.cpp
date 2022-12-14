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
struct br
{
    ll p[2],k;
}b_r;
vector <br> bor;
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll pr=1,c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
void addB(ll x)
{
    ll i,q=0;
    for(i=29;i>=0;i--)
    {
        bool be=(1ll<<i)&x;
        if(!bor[q].p[be]){bor[q].p[be]=pr++;bor.p_b(b_r);}
        q=bor[q].p[be];
        bor[q].k++;
    }
}
void del(ll x)
{
    ll i,q=0;
    for(i=29;i>=0;i--)
    {
        bool be=(1ll<<i)&x;
        q=bor[q].p[be];
        bor[q].k--;
    }
}
ll get(ll x)
{
    ll ans=0,q=0,i;
    for(i=29;i>=0;i--)
    {
        bool be=((1ll<<i)&x);
        //cout << "--+" << be << endl;
        if(bor[q].p[1^be] && bor[bor[q].p[1^be]].k)
        {
            ans+=1ll<<i;
            q=bor[q].p[1^be];
        }else
        {
            q=bor[q].p[be];
        }
    }
   return ans;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    bor.p_b(b_r);
    cin >> n;
    addB(0ll);
    while(n--)
    {
        cin >> cc >> x;
        if(cc=='+')addB(x);
        if(cc=='-')del(x);
        if(cc=='?')cout << get(x) << endl;
    }
    return 0;
}