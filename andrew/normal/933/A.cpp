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
char cc;
ll b[MAXN][3];
ll c,sc,n,m,i,j,a[MAXN],a1,b1,c1,ans,x,k;
ll get(ll l,ll r,ll x){
    return b[r][x] - b[l-1][x];
}
ll dp[MAXN];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i = 1;i <=n;i++){
        cin >> a[i];
        if(a[i] == 1)a1++;else b1++;
        b[i][1] = a1;
        b[i][2] = b1;
    }
    b1 = 0;
    for(i=n;i>=1;i--){
        if(a[i]==2)b1++;else {
            ans = max(ans,a1+b1);
            a1--;
        }
    }
    for(i=1;i<=n;i++){
            sc = 0;
            ll ae = 0;
            a1=0;
            if(i!=n)a1 = get(i+1,n,2);
            for(j=1;j<=n;j++)dp[j]=1e18;
        for(j=i;j>=1;j--){
                b1=0;
            if(j!=1)b1 = get(1,j-1,1);
            ll l = 1,r = n;
            while(l<r){
                ll c = (l+r)/2;
                if(a[j]<dp[c])r=c;else l=c+1;
            }
            sc = max(sc,l);
            dp[l] = a[j];
            ans = max(ans,a1+b1+sc);
            //(ans == 10)cout << j << " " << i << " " << a1 << " " << b1 << " " << sc << endl;
            //cout << sc << " " << a1 << " " << b1 << endl;
            //if(i==3 && j==2)cout << sc << endl;
        }
    }
    cout << ans << endl;
    return 0;
}