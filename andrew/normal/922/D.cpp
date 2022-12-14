#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll binpow(ll a,ll n)
{
    ll res = 1;
    while(n)
    {
        if(n % 2)res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}
template <typename T>
T sqr(T x)
{
    return x * x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
ll log(ll a,ll b){
    ll res = 0;
    while(a){
        a /= b;
        res++;
    }
    return res;
}
const ll shl = 1;
const ll MAXN = 1123456;
vector <ll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
struct kek{
    long double h,s;
    ll p;
};
kek ke[MAXN];
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
bool comp(kek a,kek b){
    return a.h / a.s < b.h / b.s;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> s1;
        m = s1.size();
        a1 = 0;
        sc = 0;
        for(j = 0; j < m; j++)if(s1[j] == 'h')a1++;
        ke[i].h = a1;
        b1 += a1;
        ke[i].s = m - a1;
        if(!a1)ke[i].h = -1;
        for(j = 0; j < m; j++){
            if(s1[j] == 's')sc += a1;else a1--;
        }
        ke[i].p = sc;
    }
    sort(ke,ke + n,comp);
    for(i=0;i<n;i++){
        if(ke[i].h == -1)ke[i].h = 0;
        b1 -= ke[i].h;
        ans += ke[i].p + ke[i].s * b1;
    }
    cout << ans << endl;
    return 0;
}