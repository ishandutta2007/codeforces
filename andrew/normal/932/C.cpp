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

const ll MAXN = 1123456;
vector <ll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll f(ll i,ll j){
    if(j == 1)return a[i];
    return f(a[i],j-1);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   cin >> n >> a1 >> b1;
   for(i=0;i<=n/a1;i++){
     ll c = (n - a1 * i) / b1;
     if((n - a1 * i) % b1 == 0){
            ll uk = 1;
        for(j = 0; j < i;j++){
            ll l = uk,r = uk + a1 - 1;
            a[l] = r;
            for(ll i1 = l + 1;i1 <= r;i1++)a[i1] = i1 - 1;
            uk = r + 1;
        }
        while(uk <= n){
            ll l = uk, r = uk + b1 - 1;
            a[l] = r;

            for(ll i1 = l + 1;i1 <= r;i1++)a[i1] = i1 - 1;
            uk = r + 1;
        }
        for(j = 1;j<=n;j++)cout << a[j] << " " ;
        exit(0);
     }
   }
   vout(-1);
    return 0;
}