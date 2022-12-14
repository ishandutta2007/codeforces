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
map < string , ll > mp;
string s,s1;
char cc;
ll l,r,c,sc,n,m,i,j,a[1000000],b[1000000],a1,b1,c1,ans=1e18,x,k;
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
    cin >> n;
    for(i=1;i<=n;i++)
    {
        c1=n/i;
        if(c1==0)continue;
        sc=c1*i;
        c1=(c1+i)*2;
        if(n-sc!=0)c1+=2;
        ans=min(ans,c1);
    }
    cout << ans << endl;
    return 0;
}