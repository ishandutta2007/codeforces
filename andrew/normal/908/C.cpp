#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
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
ll i,j,n;
double c,sc,m,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        double xe=m;
        for(j=1;j<i;j++)
        {
            if(abs(a[i]-a[j])-m*2<1e-9)
            {
                double l=b[j],r=1e9;
                for(ll i1=0;i1<50;i1++)
                {
                    double c=(l+r)/2;
                    double lr=sqrt(sqr(b[j]-c)+sqr(a[i]-a[j]));
                    //if(i==2)cout << l << " " << r << " " << c << "  " << lr << " " << b[j] << endl;
                    if(lr>m*2)r=c;else l=c;
                }
                xe=max(xe,l);
            }
        }
        b[i]=xe;
    }
    for(i=1;i<=n;i++)cout << fixed << setprecision(6) << b[i] << " ";cout << endl;
    return 0;
}