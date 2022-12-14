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
ll p[1000000],c,sc,n,m,i,j,a[1000000],b[1000000],a1,b1,c1,ans,x,k;
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
    for(i=0;i<=1000;i++)
        for(j=0;j<=10000;j++)
    {
        c1=1234567*i+123456*j;
        if(c1<=n)
        {
            if((n-c1)%1234==0)vout("YES");
        }
    }
    vout("NO");
    return 0;
}