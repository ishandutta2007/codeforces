#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
pair <pll, ll> a[MAXN];
ll b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)a[i].se = i;
    for(i = 1; i <= n; i++)cin >> a[i].fi.fi >> a[i].fi.se;
    for(i  = 1; i <= n; i++)a[i].fi.se = - a[i].fi.se;
    sort(a + 1, a + 1 + n);
    for(i  = 1; i <= n; i++)a[i].fi.se = - a[i].fi.se;
    ll mxj = 1;
    for(i = 2; i <= n; i++){
        if(a[mxj].fi.se >= a[i].fi.se){
            cout << a[i].se << " " << a[mxj].se << endl;
            exit(0);
        }
        if(a[mxj].fi.se < a[i].fi.se)mxj = i;
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}