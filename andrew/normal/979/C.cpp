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
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll xe;
ll dfs(ll x, ll k){
    if(b[x])return 0;
    b[x] = 1;
    if(x == xe)k = 1;
    ll i, nn = v[x].size();
    if(k == 1)a1++;
    ll xx = k;
    for(i = 0; i < nn; ++i)xx = max(dfs(v[x][i], k), xx);
    return xx;
}
void go(ll x, ll pr){
    ll i, nn = v[x].size();
    for(i = 0; i < nn; i++)if(v[x][i] != pr)go(v[x][i], x);
    b1++;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll y;
    cin >> n >> y >> x;
    xe = x;
    m = n - 1;
    while(m--){
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
    }
    a1 = b1 = 0;
    b[y] = 1;
    for(i = 0; i < v[y].size(); ++i){
        if(!dfs(v[y][i], 0))go(v[y][i], y);
    }
    b1++;
    cout << sqr(n) - n - (a1 * b1)  << endl;
    return 0;
}