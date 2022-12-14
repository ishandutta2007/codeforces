#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()
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
ll log(ll a,ll b){
    ll res=0;
    while(a){
        a/=b;
        res++;
    }
    return res;
}
const ll shl=1;
const ll MAXN=1123456;
vector <pll> v[MAXN];
set <pll> st;
stringstream ss;
map < string , ll > mp;
string s2,s1,s3;
char cc;
multiset <ll> s;
ll c,sc,n,m,i,j,b,a1,b1,c1,ans,x,k,a[4*MAXN];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=2;i*i<=3*MAXN;i++)if(!a[j]){
        j=i*i;
        while(j<=3*MAXN){
            a[j]=1;
            j+=i;
        }
    }
    m--;
    x+=3;
    v[1].p_b(m_p(n,3));
    for(i=2;i<n;i++){v[i].p_b(m_p(i+1,5));m--;x+=5;}
    for(i=x;i<=MAXN;i++)if(!a[i])break;
    //cout << i << " " << x << endl;
    sc=i-x;
    if(n>2)v[n-1][0].se+=sc;
    cout << 3 << " " << i << endl;
    for(i=1;i<n;i++){
            if(m<=0)break;
        for(j=i+1;j<=n;j++){
                if(i<2 && j==n)continue;
                if(i>1 && j==i+1)continue;
            v[i].p_b(m_p(j,1e9));
            m--;
            if(m<=0)break;
        }
    if(m<=0)break;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<v[i].size();j++)cout << i << " " << v[i][j].fi << " " << v[i][j].se << endl;
    }
    return 0;
}