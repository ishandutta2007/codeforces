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
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)cin >> a[i];
    cin >> s1;
    s1+="0";
    ll l=2;
    if(s1[0]=='1'){
    l = 1;
    s.insert(a[1]);
    }else b[1]=a[1];
    set <ll> :: iterator it;
    for(i = 2; i <= n; i++){
        if(s1[i-1] == '0' ){
            s.insert(a[i]);
            it=s.begin();
            for(j = l;j <= i;j++){
                b[j] = *it;
                ++it;
            }
            s.clear();
            l = i+1;
        }else s.insert(a[i]);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)if(a[i]!=b[i])vout("NO");
    vout("YES");
    return 0;
}