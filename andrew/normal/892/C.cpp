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
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
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
    for(i=1;i<=n;i++)cin >> a[i];
    m=n;
    for(i=1;i<=n;i++)if(a[i]==1)m--;
    if(m!=n)vout(m);
    ll mn=1e18;
    for(i=1;i<=n;i++){k=a[i];
        for(j=i;j<=n;j++,k=__gcd(k,a[j]))if(k==1 )mn=min(mn,j-i);}
    if(mn==1e18)vout(-1);
    cout << m-1+mn << endl;

    return 0;
}