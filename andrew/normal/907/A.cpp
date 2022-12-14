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
stringstream ss;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> a1 >> b1 >> c1 >> x;
    ll e1,e2,e3;
    ll l1,l2,l3;
    ll r1,r2,r3;
    l1=a1;
    r1=a1*2;
    l2=b1;
    r2=b1*2;
    l3=c1;
    r3=c1*2;
    for(i=1;i<=300;i++)
        for(j=i+1;j<=300;j++)
        for(ll i1=j+1;i1<=300;i1++)
    {
        if((l1<=i1 && i1<=r1) && (l2<=j && j<=r2) && (l3<=i && i<=r3) && x<=i && x<=j && x<=i1 && x*2>=i && x*2<j)
        {
            cout << i1 << endl << j << endl << i << endl;
            return 0;
        }
    }
    vout(-1);
    return 0;
}