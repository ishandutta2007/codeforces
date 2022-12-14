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

vector <ll> v[MAXN],va, v1;
string s1,s2,s3;
set <ll> s;
map <ll, vector <ll>> mp;
char cc;

ll a[MAXN],b[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
bool f[MAXN];
void dfs(ll x){
    if(f[x])return;
    f[x] = 1;
    if(a[x] != 2)b[m] = 1;
    ll i, nn = v[x].size();
    for(i = 0; i < nn; i++)dfs(v[x][i]);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n >> m;
   while(m--){
    cin >> a1 >> b1;
    a[a1]++;
    a[b1]++;
    v[a1].p_b(b1);
    v[b1].p_b(a1);
   }
   m = 0;
   for(i = 1; i <= n; i++)if(!f[i]){
        m++;
        dfs(i);
   }
   for(i = 1; i <= m; i++)if(!b[i])ans++;
   vout(ans);
    return 0;
}