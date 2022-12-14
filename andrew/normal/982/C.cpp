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
string s2,s3;
map <ll, ll> mp;
set <pll> s, s1;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
void dfs(ll x, ll pr){
    a[pr]++;
    ll i, nn = v[x].size();
    for(i = 0; i < nn; ++i)if(v[x][i] != pr)dfs(v[x][i], x);
    if(a[x] % 2 == 1){
        if(x != 1)ans++;
        a[pr]--;
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    m = n - 1;
    while(m--){
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
    }
    dfs(1ll, 0ll);
    if(a[0] == 0)vout(ans);
    vout(-1);
    return 0;
}